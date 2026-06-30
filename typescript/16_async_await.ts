// ============================================================
// Topic:  Async / Await  (FOCUS: async function, await, Promise.all, delay)
// Summary: Non-blocking async code — sequential vs concurrent execution.
// Run:     npx ts-node typescript/16_async_await.ts
//
// KEY DIFFERENCES:
//   Python:  asyncio + async/await (stdlib)
//   TS/JS:   Promise + async/await
//   Rust:    async fn + .await (tokio/async-std)
//   Java:    CompletableFuture / virtual threads (21+)
//   C++:     std::future / co_await (C++20 coroutines)
// ============================================================

const delay = (ms: number): Promise<void> =>
  new Promise((r) => setTimeout(r, ms));

// ----- 1. Basic async function + await — fetch a value -----
async function greet(): Promise<string> {
  await delay(10);
  return "hello";
}

// ----- 2. Sequential awaits — step1 then step2 -----
async function step1(): Promise<void> {
  await delay(10);
  console.log("step1"); // Output: step1
}

async function step2(): Promise<void> {
  await delay(10);
  console.log("step2"); // Output: step2
}

// ----- 3. Concurrent — Promise.all runs tasks in parallel -----
async function taskA(): Promise<string> {
  await delay(10);
  return "A";
}

async function taskB(): Promise<string> {
  await delay(10);
  return "B";
}

// ----- 5. Error handling — throw and catch -----
async function failingTask(): Promise<void> {
  throw new Error("boom");
}

// ----- 6. Chaining — async fn returns a value -----
async function chainedValue(): Promise<number> {
  await delay(10);
  return 42;
}

async function main(): Promise<void> {
  // ----- 1. Basic async function + await -----
  const msg = await greet();
  console.log(msg); // Output: hello

  // ----- 2. Sequential awaits -----
  await step1();
  await step2();

  // ----- 3. Concurrent — Promise.all -----
  const results = await Promise.all([taskA(), taskB()]);
  console.log(results); // Output: [ 'A', 'B' ]

  // ----- 4. Async delay -----
  await delay(10);
  console.log("done"); // Output: done

  // ----- 5. Error handling -----
  try {
    await failingTask();
  } catch (e) {
    const err = e as Error;
    console.log(`caught: ${err.message}`); // Output: caught: boom
  }

  // ----- 6. Chaining -----
  const result = await chainedValue();
  console.log(`chained: ${result}`); // Output: chained: 42
}

main();

// Cross-language note:
//   Python asyncio.run() starts the event loop; TS uses async main() or an async IIFE.
//   asyncio.gather runs coroutines concurrently; TS uses Promise.all([...]).
//   asyncio.sleep is non-blocking; TS uses new Promise + setTimeout for delays.
//   Python coroutines are single-threaded cooperative; Rust/Java use thread pools too.