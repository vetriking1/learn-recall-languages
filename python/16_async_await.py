# ============================================================
# Topic:  Async / Await  (FOCUS: async def, await, gather, sleep)
# Summary: Non-blocking coroutines — sequential vs concurrent execution.
# Run:     python python/16_async_await.py
#
# KEY DIFFERENCES:
#   Python:  asyncio + async/await (stdlib)
#   TS/JS:   Promise + async/await
#   Rust:    async fn + .await (tokio/async-std)
#   Java:    CompletableFuture / virtual threads (21+)
#   C++:     std::future / co_await (C++20 coroutines)
# ============================================================

import asyncio


# ----- 1. Basic async def + await — fetch a value -----
async def fetch_hello():
    return "hello"


# ----- 2. Sequential awaits — step1 then step2 -----
async def step1():
    await asyncio.sleep(0.01)
    print("step1")  # Output: step1


async def step2():
    await asyncio.sleep(0.01)
    print("step2")  # Output: step2


# ----- 3. Concurrent — gather two tasks -----
async def task_a():
    await asyncio.sleep(0.01)
    return "A"


async def task_b():
    await asyncio.sleep(0.01)
    return "B"


# ----- 5. Error handling — raise and catch -----
async def failing_task():
    raise ValueError("boom")


# ----- 6. Chaining — async fn returns a value -----
async def chained_value():
    await asyncio.sleep(0.01)
    return 42


async def main():
    # ----- 1. Basic async def + await -----
    print(await fetch_hello())  # Output: hello

    # ----- 2. Sequential awaits -----
    await step1()
    await step2()

    # ----- 3. Concurrent — asyncio.gather -----
    results = await asyncio.gather(task_a(), task_b())
    print(results)  # Output: ['A', 'B']

    # ----- 4. Async delay -----
    await asyncio.sleep(0.01)
    print("done")  # Output: done

    # ----- 5. Error handling -----
    try:
        await failing_task()
    except ValueError as e:
        print(f"caught: {e}")  # Output: caught: boom

    # ----- 6. Chaining -----
    result = await chained_value()
    print(f"chained: {result}")  # Output: chained: 42


asyncio.run(main())

# Cross-language note:
#   Python asyncio.run() starts the event loop; TS uses top-level await or IIFE.
#   asyncio.gather runs coroutines concurrently; TS uses Promise.all([...]).
#   asyncio.sleep is non-blocking; TS uses setTimeout wrapped in a Promise.
#   Python coroutines are single-threaded cooperative; Rust/Java use thread pools too.