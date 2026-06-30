// ============================================================
// Topic:  Multithreading & Multiprocessing  (FOCUS: Thread, lock, Mutex, Process)
// Summary: OS threads, synchronization, and separate processes.
// Run:     dotnet script csharp/17_threads_and_processes.cs
//
// KEY DIFFERENCES:
//   C#:     System.Threading.Thread, lock, Mutex, System.Diagnostics.Process
//   Python: threading.Thread, Lock, multiprocessing.Process
//   TS/JS:  Worker threads (worker_threads) — single-threaded event loop by default
//   Rust:   std::thread, Mutex<T>, std::process::Command
//   Java:   Thread, synchronized, ProcessBuilder
// ============================================================

using System;
using System.Diagnostics;
using System.Threading;

// ----- 1. Thread — start, run concurrently, Join -----
var workerReady = new ManualResetEventSlim(false);   // signal    | Python: threading.Event() | Java: CountDownLatch
Thread worker = new Thread(() =>
{
    Console.WriteLine("worker");                     // worker    | Python: print in thread target | Rust: thread::spawn closure
    workerReady.Set();                               // unblock main after worker prints
});
worker.Start();                                      // start     | Python: t.start() | Java: t.start()
workerReady.Wait();                                  // wait      | ensures worker prints before main
Console.WriteLine("main");                           // main      | main thread continues
worker.Join();                                       // join      | Python: t.join() | Rust: handle.join()
Console.WriteLine("joined");                         // joined    | worker finished

// ----- 2. lock — protect shared counter (two threads × 1000) -----
int counter = 0;
object counterLock = new object();                   // lock obj  | Python: threading.Lock() | Java: synchronized(this)
void IncrementCounter(int times)
{
    for (int i = 0; i < times; i++)
    {
        lock (counterLock)                           // lock      | Python: with lock: | Rust: mutex.lock()
        {
            counter++;
        }
    }
}
Thread t1 = new Thread(() => IncrementCounter(1000));
Thread t2 = new Thread(() => IncrementCounter(1000));
t1.Start();
t2.Start();
t1.Join();
t2.Join();
Console.WriteLine($"counter: {counter}");            // counter: 2000 | without lock would race below 2000

// ----- 3. Mutex — alternative sync primitive (ordered A then B) -----
Mutex abMutex = new Mutex();                         // Mutex     | cross-process capable | Python: multiprocessing.Lock
Thread threadA = new Thread(() =>
{
    abMutex.WaitOne();                               // acquire   | Python: lock.acquire()
    Console.WriteLine("A");                          // A         | first labeled output
    abMutex.ReleaseMutex();                          // release   | Python: lock.release()
});
Thread threadB = new Thread(() =>
{
    abMutex.WaitOne();
    Console.WriteLine("B");                          // B         | second after A (serialized by mutex)
    abMutex.ReleaseMutex();
});
threadA.Start();                                     // run A     | join before B for deterministic order
threadA.Join();
threadB.Start();
threadB.Join();
abMutex.Dispose();

// ----- 4. Process — separate address space, spawn child -----
var psi = new ProcessStartInfo
{
    FileName = "cmd.exe",                            // shell     | Python: subprocess.run(["cmd", "/c", ...])
    Arguments = "/c echo child",                     // child cmd | prints "child" from child process
    UseShellExecute = false,
};
Process child = Process.Start(psi)!;                 // spawn     | Python: multiprocessing.Process | Rust: Command::new
child.WaitForExit();                                 // wait      | block until child exits
Console.WriteLine($"exit: {child.ExitCode}");        // exit: 0   | 0 = success | Python: p.exitcode
child.Dispose();

// Cross-language note:
//   Thread = shared memory; Process = isolated memory — use threads for CPU-bound shared data, processes for isolation.
//   lock is syntactic sugar for Monitor.Enter/Exit — faster than Mutex when only one process needs sync.
//   Mutex works across processes; lock does not. Prefer lock for in-process counters.
//   Process.Start spawns a new OS process — heavier than Thread.Start but avoids GIL-style contention (N/A in C#).
//   dotnet script runs top-level statements; a .csproj needs explicit Main or host for the same flow.