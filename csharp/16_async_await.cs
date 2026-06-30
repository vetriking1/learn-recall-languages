// ============================================================
// Topic:  Async / Await  (FOCUS: Task, await, Task.WhenAll, delays, errors)
// Summary: Non-blocking async methods — method recall.
// Run:     dotnet script csharp/16_async_await.cs
//
// KEY DIFFERENCES:
//   C#:     async Task / async Task<T>, await, Task.WhenAll
//   Python: async def, await, asyncio.gather
//   TS/JS:  async function, await, Promise.all
//   Rust:   async fn, .await, tokio::join!
//   Java:   CompletableFuture.supplyAsync — no async/await keyword until recent patterns
// ============================================================

using System;
using System.Threading.Tasks;

// ----- 1. async + await — basic async method -----
async Task<string> SayHello()
{
    await Task.Delay(10);                       // yield     | Python: await asyncio.sleep(0.01) | TS: await delay(10)
    return "hello";
}
Console.WriteLine(await SayHello());            // hello     | TS: await sayHello() | Python: await say_hello()

// ----- 2. Sequential awaits — one after another -----
async Task<string> Step1() { await Task.Delay(10); return "step1"; }
async Task<string> Step2() { await Task.Delay(10); return "step2"; }
Console.WriteLine(await Step1());               // step1     | first task finishes before second starts
Console.WriteLine(await Step2());               // step2     | Python: s1 = await step1(); s2 = await step2()

// ----- 3. Concurrent Task.WhenAll — run in parallel -----
async Task<string> WorkA() { await Task.Delay(10); return "A"; }
async Task<string> WorkB() { await Task.Delay(10); return "B"; }
string[] both = await Task.WhenAll(WorkA(), WorkB());
Console.WriteLine($"[{string.Join(", ", both)}]"); // [A, B] | Python: await asyncio.gather(work_a(), work_b()) | TS: Promise.all([workA(), workB()])

// ----- 4. Task.Delay — non-blocking pause -----
async Task DelayDemo()
{
    await Task.Delay(10);                       // delay 10ms | Python: await asyncio.sleep(0.01) | TS: await new Promise(r => setTimeout(r, 10))
    Console.WriteLine("done");                  // done
}
await DelayDemo();

// ----- 5. try/catch in async — exception handling -----
async Task Boom()
{
    await Task.Delay(10);
    throw new Exception("boom");
}
try
{
    await Boom();
}
catch (Exception ex)
{
    Console.WriteLine($"caught: {ex.Message}"); // caught: boom | TS: try { await boom() } catch (e) | Python: try/except around await
}

// ----- 6. Chaining async results -----
async Task<int> GetValue() { await Task.Delay(10); return 42; }
async Task<string> Chain()
{
    int n = await GetValue();                   // await intermediate | Python: n = await get_value()
    return $"chained: {n}";
}
Console.WriteLine(await Chain());               // chained: 42 | pipe async results through await

// Cross-language note:
//   C# async/await compiles to a state machine — same idea as TS/JS Promises under the hood.
//   Task.WhenAll = Python asyncio.gather / JS Promise.all — tasks run concurrently, results keep input order.
//   Sequential await blocks only the current async method, not the thread (unlike Thread.Sleep).
//   dotnet script supports top-level await; a normal .csproj needs an async Main or host builder.