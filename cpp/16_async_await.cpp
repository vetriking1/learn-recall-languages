// ============================================================
// Topic:  Async / Await  (FOCUS: std::async, std::future, .get(), delays)
// Summary: Concurrent tasks via futures — sequential vs parallel execution.
// Run:     g++ -std=c++17 cpp/16_async_await.cpp -o cpp/16_async_await && cpp/16_async_await
//
// KEY DIFFERENCES:
//   C++:     std::async + std::future + .get()  (C++17 — no async/await keyword)
//   C#:      async Task / await
//   Python:  async def / await / asyncio.gather
//   TS/JS:   async function / await / Promise.all
//   Rust:    async fn / .await / tokio::join!
//   Java:    CompletableFuture.supplyAsync
//   C++20:   co_await coroutines — needs -std=c++20 and custom awaitables
// ============================================================

#include <chrono>
#include <future>
#include <iostream>
#include <stdexcept>
#include <string>
#include <thread>

std::string do_say_hello() {
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    return "hello";
}

std::string do_step1() {
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    return "step1";
}

std::string do_step2() {
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    return "step2";
}

std::string do_work_a() {
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    return "A";
}

std::string do_work_b() {
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    return "B";
}

int do_boom() {
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    throw std::runtime_error("boom");
}

int do_get_value() {
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    return 42;
}

std::string do_delay_demo() {
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    return "done";
}

std::string do_chain() {
    int n = do_get_value();
    return "chained: " + std::to_string(n);
}

int main() {
    // ----- 1. std::async + future.get() — like await -----
    std::cout << std::async(std::launch::async, do_say_hello).get() << std::endl;
    // Output: hello

    // ----- 2. Sequential .get() — one after another -----
    std::cout << std::async(std::launch::async, do_step1).get() << std::endl;
    // Output: step1
    std::cout << std::async(std::launch::async, do_step2).get() << std::endl;
    // Output: step2

    // ----- 3. Concurrent — launch both, then collect results -----
    auto fa = std::async(std::launch::async, do_work_a);
    auto fb = std::async(std::launch::async, do_work_b);
    std::cout << "[" << fa.get() << ", " << fb.get() << "]" << std::endl;
    // Output: [A, B]

    // ----- 4. sleep_for — delay inside async task -----
    std::cout << std::async(std::launch::async, do_delay_demo).get() << std::endl;
    // Output: done

    // ----- 5. try/catch around .get() — exception propagation -----
    try {
        std::async(std::launch::async, do_boom).get();
    } catch (const std::exception& ex) {
        std::cout << "caught: " << ex.what() << std::endl;
    }
    // Output: caught: boom

    // ----- 6. Chaining async results -----
    std::cout << std::async(std::launch::async, do_chain).get() << std::endl;
    // Output: chained: 42

    // Cross-language note:
    //   C++ has no async/await keyword in C++17 — .get() on std::future is the blocking "await".
    //   Launch tasks first, then .get() all of them for parallelism (like Promise.all / gather).
    //   C++20 co_await + coroutines mirror async/await syntax but need custom promise types.
    return 0;
}