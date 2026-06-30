// ============================================================
// Topic:  Multithreading & Multiprocessing
// Summary: std::thread::spawn, join, Mutex, std::process::Command child process.
// Run:     rustc --edition 2021 rust/17_threads_and_processes.rs -o rust/17_threads_and_processes.exe && rust/17_threads_and_processes.exe
//
// KEY DIFFERENCES:
//   Python:  threading.Thread + join, multiprocessing.Process, Lock
//   TS/JS:   Worker threads (worker_threads) / Web Workers; child_process.spawn
//   Rust:    std::thread, Arc<Mutex<T>>, std::process::Command (no GIL — true OS threads)
//   Java:    Thread / ExecutorService; ProcessBuilder for child processes
//   C++:     std::thread, std::mutex; fork/exec or std::system for child processes
// ============================================================

use std::process::Command;
use std::sync::{Arc, Mutex};
use std::thread;

fn main() {
    // ----- 1. spawn + join — worker thread runs, then main continues -----
    let handle = thread::spawn(|| {
        println!("worker"); // Output: worker   | Python: threading.Thread(target=worker).start()
    });
    handle.join().unwrap();
    println!("main"); // Output: main
    println!("joined"); // Output: joined   | Python: t.join()

    // ----- 2. Mutex — shared counter across threads (Arc = shared ownership) -----
    let counter = Arc::new(Mutex::new(0));
    let mut handles = vec![];
    for _ in 0..2 {
        let counter = Arc::clone(&counter);
        handles.push(thread::spawn(move || {
            for _ in 0..1000 {
                *counter.lock().unwrap() += 1;
            }
        }));
    }
    for h in handles {
        h.join().unwrap();
    }
    println!("counter: {}", *counter.lock().unwrap()); // Output: counter: 2000   | Python: Lock around += 1
    // Cross-language: Arc<Mutex<T>> = Python threading.Lock + shared ref; Rust enforces Send.

    // ----- 3. Two threads — sequential join for deterministic A then B -----
    let h_a = thread::spawn(|| println!("A")); // Output: A
    h_a.join().unwrap();
    let h_b = thread::spawn(|| println!("B")); // Output: B
    h_b.join().unwrap();
    // Python: Thread(target=print_a).start(); same pattern with join order.

    // ----- 4. Child process — Command spawns a shell echo -----
    #[cfg(windows)]
    let mut child = Command::new("cmd")
        .args(["/c", "echo", "child"])
        .spawn()
        .expect("failed to spawn child");
    #[cfg(not(windows))]
    let mut child = Command::new("sh")
        .args(["-c", "echo child"])
        .spawn()
        .expect("failed to spawn child");
    // Output: child   (printed by child stdout, inherited by parent)
    let status = child.wait().expect("failed to wait on child");
    println!("exit: {}", status.code().unwrap_or(-1)); // Output: exit: 0   | Python: subprocess.run(...).returncode

    // Cross-language note:
    //   Rust threads are 1:1 OS threads (no GIL). Mutex prevents data races at compile + runtime.
    //   Command = Python subprocess / Java ProcessBuilder / C++ std::system or posix_spawn.
    //   For heavy CPU parallelism across cores, same process threads share memory via Arc<Mutex>.
    //   Separate processes (Command) get isolated memory — like Python multiprocessing.Process.
}