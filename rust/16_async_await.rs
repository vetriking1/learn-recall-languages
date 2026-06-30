// ============================================================
// Topic:  Async / Await  (FOCUS: async fn, .await, threads as runnable stand-in)
// Summary: async/await syntax + std::thread for runnable concurrent demos (no tokio).
// Run:     rustc --edition 2021 rust/16_async_await.rs -o rust/16_async_await.exe && rust/16_async_await.exe
//
// KEY DIFFERENCES:
//   Python:  asyncio + async/await (stdlib)
//   TS/JS:   Promise + async/await
//   Rust:    async fn + .await (tokio/async-std for a real runtime)
//   Java:    CompletableFuture / virtual threads (21+)
//   C++:     std::future / co_await (C++20 coroutines)
// ============================================================

use std::future::Future;
use std::pin::pin;
use std::task::{Context, Poll, RawWaker, RawWakerVTable, Waker};
use std::thread;
use std::time::Duration;

// ----- Minimal block_on — polls a future once; works for immediately-ready futures only -----
fn noop_waker() -> Waker {
    const VTABLE: RawWakerVTable = RawWakerVTable::new(
        |_| RawWaker::new(std::ptr::null(), &VTABLE),
        |_| {},
        |_| {},
        |_| {},
    );
    // SAFETY: no-op vtable; future never needs a real wake-up for fetch_hello().
    unsafe { Waker::from_raw(RawWaker::new(std::ptr::null(), &VTABLE)) }
}

fn block_on<F: Future>(future: F) -> F::Output {
    let waker = noop_waker();
    let mut context = Context::from_waker(&waker);
    let mut future = pin!(future);
    loop {
        match future.as_mut().poll(&mut context) {
            Poll::Ready(output) => return output,
            Poll::Pending => {
                panic!("future pending — real async timers/I/O need tokio or async-std");
            }
        }
    }
}

// ----- 1. Basic async fn + .await — fetch a value (syntax) -----
async fn fetch_hello() -> &'static str {
    // Real Rust async would .await I/O or timers here (tokio::time::sleep, etc.).
    "hello"
}

// ----- 2. Sequential awaits — step1 then step2 (runnable via threads) -----
fn step1() {
    thread::sleep(Duration::from_millis(10));
    println!("step1"); // Output: step1
}

fn step2() {
    thread::sleep(Duration::from_millis(10));
    println!("step2"); // Output: step2
}

// ----- 3. Concurrent — spawn two tasks (runnable via threads) -----
fn task_a() -> &'static str {
    thread::sleep(Duration::from_millis(10));
    "A"
}

fn task_b() -> &'static str {
    thread::sleep(Duration::from_millis(10));
    "B"
}

// ----- 5. Error handling — return Err (like Python raise ValueError) -----
fn failing_task() -> Result<(), &'static str> {
    Err("boom")
}

// ----- 6. Chaining — fn returns a value -----
fn chained_value() -> i32 {
    thread::sleep(Duration::from_millis(10));
    42
}

fn main() {
    // ----- 1. Basic async fn + .await — block_on for immediate future -----
    let msg = block_on(fetch_hello());
    println!("{}", msg); // Output: hello   | Python: await fetch_value() | C#: await SayHello()
    // Cross-language: std has no async runtime; tokio/async-std provide .await on sleep/I/O.

    // ----- 2. Sequential awaits — one after another -----
    step1();
    step2(); // Python: await step1(); await step2()

    // ----- 3. Concurrent — thread::spawn + JoinHandle (like asyncio.gather) -----
    let handle_a = thread::spawn(|| task_a());
    let handle_b = thread::spawn(|| task_b());
    let a = handle_a.join().unwrap();
    let b = handle_b.join().unwrap();
    println!(r#"["{}", "{}"]"#, a, b); // Output: ["A", "B"]   | Python: ['A', 'B']
    // Runnable stand-in for: async { join!(task_a(), task_b()) } with tokio.

    // ----- 4. Async delay -----
    thread::sleep(Duration::from_millis(10));
    println!("done"); // Output: done   | Python: await asyncio.sleep(0.01)

    // ----- 5. Error handling -----
    match failing_task() {
        Err(e) => println!("caught: {}", e), // Output: caught: boom
        Ok(_) => {}
    } // Python: try/except ValueError around await failing_task()

    // ----- 6. Chaining -----
    let result = chained_value();
    println!("chained: {}", result); // Output: chained: 42   | Python: await chained_value()

    // Cross-language note:
    //   Rust async/await compiles to a state machine Future — same idea as TS/JS Promises.
    //   std has no executor; tokio::main / async-std::main start the runtime (like asyncio.run).
    //   tokio::join! / futures::future::join = Python asyncio.gather / JS Promise.all.
    //   Sections 2–4 use std::thread here so this file runs with rustc alone (no external crates).
}