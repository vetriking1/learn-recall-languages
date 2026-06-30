// ============================================================
// Topic:  Multithreading & Multiprocessing  (FOCUS: std::thread, std::mutex, join, processes)
// Summary: OS threads with mutex sync — separate process via std::system / CreateProcess.
// Run:     g++ -std=c++17 cpp/17_threads_and_processes.cpp -o cpp/17_threads_and_processes && cpp/17_threads_and_processes
//
// KEY DIFFERENCES:
//   C++:     std::thread + std::mutex + join()  |  fork()/exec (Unix) or CreateProcess (Win)
//   Python:  threading.Thread / multiprocessing.Process
//   Java:    Thread / Runnable / ProcessBuilder
//   C#:      Thread / Task.Run / Process.Start
//   Rust:    std::thread::spawn / std::process::Command
//   TS/JS:   Worker threads (worker_threads) / child_process
// ============================================================

#include <atomic>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>  // std::thread, join()

int main(int argc, char* argv[]) {
    // Child process mode — spawned by parent below; only prints "child".
    if (argc > 1 && std::string(argv[1]) == "child") {
        std::cout << "child" << std::endl;
        return 0;
    }

    // ----- 1. std::thread + join() — worker runs, main waits -----
    std::atomic<bool> worker_done{false};
    std::thread worker([&] {
        std::cout << "worker" << std::endl;
        worker_done.store(true);
    });
    while (!worker_done.load()) {
        std::this_thread::yield();  // ensure worker prints before main
    }
    std::cout << "main" << std::endl;
    worker.join();
    std::cout << "joined" << std::endl;
    // Output: worker
    // Output: main
    // Output: joined

    // ----- 2. std::mutex — two threads increment shared counter -----
    int counter = 0;
    std::mutex mtx;
    auto increment = [&](int times) {
        for (int i = 0; i < times; ++i) {
            std::lock_guard<std::mutex> lock(mtx);
            ++counter;
        }
    };
    std::thread inc_a(increment, 1000);
    std::thread inc_b(increment, 1000);
    inc_a.join();
    inc_b.join();
    std::cout << "counter: " << counter << std::endl;
    // Output: counter: 2000

    // ----- 3. Two threads — sequential join keeps A before B -----
    std::thread thread_a([] { std::cout << "A" << std::endl; });
    thread_a.join();
    std::thread thread_b([] { std::cout << "B" << std::endl; });
    thread_b.join();
    // Output: A
    // Output: B

    // ----- 4. Separate process — child prints "child", parent waits -----
#if defined(_WIN32)
    const char* child_cmd = "cpp\\17_threads_and_processes.exe child";
    int exit_code = std::system(child_cmd);
#else
    int exit_code = std::system("cpp/17_threads_and_processes child");
#endif
    std::cout << "exit: " << exit_code << std::endl;
    // Output: child   (printed by child process stdout)
    // Output: exit: 0

    // Cross-language note:
    //   C++17 has no built-in async/await — use std::thread for shared-memory concurrency.
    //   std::mutex + lock_guard protect data races; always join() or detach() every thread.
    //   Processes are separate address spaces — spawn via system(), fork+exec, or CreateProcess.
    //   Unlike Python's GIL, C++ threads can run Python-style CPU work in parallel on multiple cores.
    return 0;
}