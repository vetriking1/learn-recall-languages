// ============================================================
// Topic:  Multithreading & Multiprocessing  (FOCUS: Thread + ProcessBuilder)
// Summary: Threads with join/synchronization; child processes via ProcessBuilder.
// Run:     java java/17_threads_and_processes.java   (Java 11+ single-file launch)
//
// KEY DIFFERENCES:
//   Python:  threading + multiprocessing / subprocess
//   TS/JS:   Worker threads (node:worker_threads) — no true multiprocessing in browser
//   Rust:    std::thread + std::process::Command
//   Java:    Thread / ExecutorService + ProcessBuilder (no async/await)
//   C++:     std::thread + fork/exec or std::process (C++23)
// ============================================================

import java.util.concurrent.CountDownLatch;
import java.util.concurrent.locks.ReentrantLock;

public class ThreadsAndProcesses {

    // ----- 1. Basic thread — start, run, join -----
    static void basicThread() throws InterruptedException {
        CountDownLatch workerPrinted = new CountDownLatch(1);
        Thread worker = new Thread(() -> {
            System.out.println("worker");                     // Output: worker
            workerPrinted.countDown();
        });
        worker.start();
        workerPrinted.await();
        System.out.println("main");                             // Output: main
        worker.join();
        System.out.println("joined");                           // Output: joined
    }

    // ----- 2. Shared counter — ReentrantLock protects increments -----
    static void lockedCounter() throws InterruptedException {
        final int[] counter = {0};
        ReentrantLock lock = new ReentrantLock();
        Runnable increment = () -> {
            for (int i = 0; i < 1000; i++) {
                lock.lock();
                try {
                    counter[0]++;
                } finally {
                    lock.unlock();
                }
            }
        };
        Thread t1 = new Thread(increment);
        Thread t2 = new Thread(increment);
        t1.start();
        t2.start();
        t1.join();
        t2.join();
        System.out.println("counter: " + counter[0]);         // Output: counter: 2000
    }

    // ----- 3. Two threads — sequential join prints A then B -----
    static void twoThreads() throws InterruptedException {
        Thread threadA = new Thread(() -> System.out.println("A")); // Output: A
        Thread threadB = new Thread(() -> System.out.println("B")); // Output: B
        threadA.start();
        threadA.join();
        threadB.start();
        threadB.join();
    }

    // ----- 4. Child process — ProcessBuilder spawns echo "child" -----
    static void childProcess() throws Exception {
        ProcessBuilder pb;
        if (System.getProperty("os.name").toLowerCase().contains("win")) {
            pb = new ProcessBuilder("cmd", "/c", "echo", "child");
        } else {
            pb = new ProcessBuilder("sh", "-c", "echo child");
        }
        pb.inheritIO();
        Process child = pb.start();
        int exitCode = child.waitFor();
        System.out.println("exit: " + exitCode);                // Output: exit: 0
    }

    public static void main(String[] args) throws Exception {
        // ----- 1. Basic thread -----
        basicThread();

        // ----- 2. Synchronized counter (ReentrantLock) -----
        lockedCounter();

        // ----- 3. Two threads -----
        twoThreads();

        // ----- 4. Child process -----
        childProcess();

        // Cross-language note:
        //   Java has threads (Thread / synchronized / locks) and processes (ProcessBuilder).
        //   No async/await — use CompletableFuture or virtual threads (21+) for async I/O.
        //   ProcessBuilder is like Python subprocess or Rust std::process::Command.
    }
}