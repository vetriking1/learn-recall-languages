# ============================================================
# Topic:  Multithreading & Multiprocessing  (FOCUS: threads, locks, processes)
# Summary: Concurrent execution — shared-memory threads vs separate processes.
# Run:     python python/17_threads_and_processes.py
#
# KEY DIFFERENCES:
#   Python:  threading + multiprocessing (stdlib)
#   TS/JS:   Web Workers (no shared memory by default)
#   Rust:    std::thread + std::sync::Mutex | rayon
#   Java:    Thread / ExecutorService | ProcessBuilder
#   C++:     std::thread + std::mutex | fork()/exec()
# ============================================================

import threading
import multiprocessing


# ----- 1. Spawn thread — worker prints -----
def worker_spawn():
    print("worker", flush=True)  # Output: worker


# ----- 2. Join — main waits for thread -----
def worker_join():
    pass


# ----- 3. Lock — shared counter with mutex -----
counter = 0
lock = threading.Lock()


def increment_locked():
    global counter
    for _ in range(1000):
        with lock:
            counter += 1


# ----- 4. Multiple threads — collect results -----
thread_results = {}


def worker_a():
    thread_results["a"] = "A"


def worker_b():
    thread_results["b"] = "B"


# ----- 5 & 6. Separate process + join -----
def child_process():
    print("child", flush=True)  # Output: child


def main():
    # ----- 1. Spawn thread -----
    t = threading.Thread(target=worker_spawn)
    t.start()
    t.join()

    # ----- 2. Join -----
    print("main", flush=True)  # Output: main
    t = threading.Thread(target=worker_join)
    t.start()
    t.join()
    print("joined", flush=True)  # Output: joined

    # ----- 3. Lock / mutex -----
    global counter
    counter = 0
    t1 = threading.Thread(target=increment_locked)
    t2 = threading.Thread(target=increment_locked)
    t1.start()
    t2.start()
    t1.join()
    t2.join()
    print(f"counter: {counter}", flush=True)  # Output: counter: 2000

    # ----- 4. Multiple threads -----
    thread_results.clear()
    t_a = threading.Thread(target=worker_a)
    t_b = threading.Thread(target=worker_b)
    t_a.start()
    t_b.start()
    t_a.join()
    t_b.join()
    print(thread_results["a"], flush=True)  # Output: A
    print(thread_results["b"], flush=True)  # Output: B

    # ----- 5. Separate process -----
    p = multiprocessing.Process(target=child_process)
    p.start()

    # ----- 6. Process join -----
    p.join()
    print(f"exit: {p.exitcode}", flush=True)  # Output: exit: 0


if __name__ == "__main__":
    main()

# Cross-language note:
#   Python threads share memory (GIL limits CPU parallelism); processes are isolated.
#   threading.Lock maps to mutex / synchronized blocks in Java, C++, and Rust.
#   multiprocessing.Process is like Java ProcessBuilder or C fork()+exec().
#   On Windows, guard multiprocessing entry points with if __name__ == "__main__".