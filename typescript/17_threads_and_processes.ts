// ============================================================
// Topic:  Multithreading & Multiprocessing  (FOCUS: worker_threads, child_process)
// Summary: Concurrent execution — shared-memory threads vs separate processes.
// Run:     npx ts-node typescript/17_threads_and_processes.ts
//
// KEY DIFFERENCES:
//   Python:  threading + multiprocessing (stdlib)
//   TS/JS:   worker_threads + child_process (Node.js stdlib)
//   Rust:    std::thread + std::sync::Mutex | std::process::Command
//   Java:    Thread / ExecutorService | ProcessBuilder
//   C++:     std::thread + std::mutex | fork()/exec()
// ============================================================

import { createRequire } from "module";
import * as path from "path";
import { spawnSync } from "child_process";
import {
  Worker,
  isMainThread,
  parentPort,
  workerData,
} from "worker_threads";

const nodeRequire = createRequire(__filename);
const tsconfigPath = path.join(__dirname, "tsconfig.json");
const workerOpts = {
  execArgv: ["-r", nodeRequire.resolve("ts-node/register")],
  env: { ...process.env, TS_NODE_PROJECT: tsconfigPath },
};

// ----- Child process entry (separate OS process) -----
if (process.argv.includes("--child")) {
  console.log("child"); // Output: child
  process.exit(0);
}

// ----- Worker thread entry (same process, separate thread) -----
if (!isMainThread) {
  const job = workerData.job as string;

  // ----- 1. Spawn thread — worker prints -----
  if (job === "spawn") {
    console.log("worker"); // Output: worker
  }
  // ----- 2. Join — empty worker (main prints after first join) -----
  else if (job === "join") {
    /* no-op */
  }
  // ----- 3. Lock — shared counter with mutex -----
  else if (job === "increment") {
    const shared = workerData.shared as SharedArrayBuffer;
    const lock = new Int32Array(shared, 0, 1);
    const counter = new Int32Array(shared, 4, 1);
    for (let i = 0; i < 1000; i++) {
      while (Atomics.compareExchange(lock, 0, 0, 1) !== 0) {
        /* spin */
      }
      Atomics.add(counter, 0, 1);
      Atomics.store(lock, 0, 0);
    }
  }
  // ----- 4. Multiple threads — collect results -----
  else if (job === "workerA") {
    parentPort?.postMessage({ key: "a", value: "A" });
  } else if (job === "workerB") {
    parentPort?.postMessage({ key: "b", value: "B" });
  }
} else {
  function runWorker(data: Record<string, unknown>): Promise<void> {
    return new Promise((resolve, reject) => {
      const w = new Worker(__filename, { workerData: data, ...workerOpts });
      w.on("error", reject);
      w.on("exit", (code) => {
        if (code === 0) resolve();
        else reject(new Error(`worker exited ${code}`));
      });
    });
  }

  function runWorkerMessage<T>(data: Record<string, unknown>): Promise<T> {
    return new Promise((resolve, reject) => {
      const w = new Worker(__filename, { workerData: data, ...workerOpts });
      w.on("message", (msg) => resolve(msg as T));
      w.on("error", reject);
      w.on("exit", (code) => {
        if (code !== 0) reject(new Error(`worker exited ${code}`));
      });
    });
  }

  async function main(): Promise<void> {
    // ----- 1. Spawn thread -----
    await runWorker({ job: "spawn" });

    // ----- 2. Join -----
    console.log("main"); // Output: main
    await runWorker({ job: "join" });
    console.log("joined"); // Output: joined

    // ----- 3. Lock / mutex -----
    const shared = new SharedArrayBuffer(8);
    await Promise.all([
      runWorker({ job: "increment", shared }),
      runWorker({ job: "increment", shared }),
    ]);
    const counter = new Int32Array(shared, 4, 1);
    console.log(`counter: ${counter[0]}`); // Output: counter: 2000

    // ----- 4. Multiple threads -----
    const threadResults: Record<string, string> = {};
    const [msgA, msgB] = await Promise.all([
      runWorkerMessage<{ key: string; value: string }>({ job: "workerA" }),
      runWorkerMessage<{ key: string; value: string }>({ job: "workerB" }),
    ]);
    threadResults[msgA.key] = msgA.value;
    threadResults[msgB.key] = msgB.value;
    console.log(threadResults["a"]); // Output: A
    console.log(threadResults["b"]); // Output: B

    // ----- 5. Separate process -----
    const root = path.resolve(__dirname, "..");
    const result = spawnSync(
      "npx",
      ["ts-node", "typescript/17_threads_and_processes.ts", "--child"],
      { stdio: "inherit", shell: true, cwd: root }
    );

    // ----- 6. Process join -----
    console.log(`exit: ${result.status}`); // Output: exit: 0
  }

  main();
}

// Cross-language note:
//   Python threads share memory (GIL limits CPU parallelism); processes are isolated.
//   worker_threads + SharedArrayBuffer + Atomics map to threading.Lock + shared globals.
//   child_process.spawn is like Python multiprocessing.Process or Java ProcessBuilder.
//   On Windows, guard fork/spawn entry points so child processes do not re-run main logic.