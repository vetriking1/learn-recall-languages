// ============================================================
// Topic:  Async / Await  (FOCUS: CompletableFuture — Java's async/await equivalent)
// Summary: Non-blocking async with CompletableFuture; no async/await keywords.
// Run:     java java/16_async_await.java   (Java 11+ single-file launch)
//
// KEY DIFFERENCES:
//   Python:  asyncio + async/await (stdlib)
//   TS/JS:   Promise + async/await
//   Rust:    async fn + .await (tokio/async-std)
//   Java:    CompletableFuture (no async/await syntax) / virtual threads (21+)
//   C++:     std::future / co_await (C++20 coroutines)
// ============================================================

import java.util.Arrays;
import java.util.List;
import java.util.concurrent.CompletableFuture;

public class AsyncAwait {

    // ----- 1. Basic async — supplyAsync + join (like await) -----
    static CompletableFuture<String> fetchHello() {
        return CompletableFuture.supplyAsync(() -> "hello");
    }

    // ----- 2. Sequential — step1 then step2 -----
    static CompletableFuture<Void> step1() {
        return CompletableFuture.runAsync(() -> {
            sleep(10);
            System.out.println("step1");                      // Output: step1
        });
    }

    static CompletableFuture<Void> step2() {
        return CompletableFuture.runAsync(() -> {
            sleep(10);
            System.out.println("step2");                      // Output: step2
        });
    }

    // ----- 3. Concurrent — two supplyAsync tasks -----
    static CompletableFuture<String> taskA() {
        return CompletableFuture.supplyAsync(() -> {
            sleep(10);
            return "A";
        });
    }

    static CompletableFuture<String> taskB() {
        return CompletableFuture.supplyAsync(() -> {
            sleep(10);
            return "B";
        });
    }

    // ----- 5. Error handling — complete exceptionally -----
    static CompletableFuture<Void> failingTask() {
        return CompletableFuture.runAsync(() -> {
            throw new RuntimeException("boom");
        });
    }

    // ----- 6. Chaining — supplyAsync returns a value -----
    static CompletableFuture<Integer> chainedValue() {
        return CompletableFuture.supplyAsync(() -> {
            sleep(10);
            return 42;
        });
    }

    static void sleep(int ms) {
        try {
            Thread.sleep(ms);
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }

    public static void main(String[] args) {
        // ----- 1. Basic async — supplyAsync + join -----
        String msg = fetchHello().join();
        System.out.println(msg);                                // Output: hello

        // ----- 2. Sequential awaits — thenCompose chains order -----
        step1().thenCompose(v -> step2()).join();

        // ----- 3. Concurrent — CompletableFuture.allOf -----
        CompletableFuture<String> fa = taskA();
        CompletableFuture<String> fb = taskB();
        CompletableFuture.allOf(fa, fb).join();
        List<String> results = Arrays.asList(fa.join(), fb.join());
        System.out.println(results);                            // Output: [A, B]

        // ----- 4. Async delay -----
        CompletableFuture.runAsync(() -> sleep(10)).join();
        System.out.println("done");                             // Output: done

        // ----- 5. Error handling -----
        try {
            failingTask().join();
        } catch (Exception e) {
            Throwable cause = e.getCause() != null ? e.getCause() : e;
            System.out.println("caught: " + cause.getMessage()); // Output: caught: boom
        }

        // ----- 6. Chaining -----
        int result = chainedValue()
                .thenApply(n -> n)                              // like .then(x => x)
                .join();
        System.out.println("chained: " + result);               // Output: chained: 42

        // Cross-language note:
        //   Java has NO async/await keywords — use CompletableFuture instead.
        //   .join() blocks like await; .thenApply/.thenCompose chain like .then().
        //   CompletableFuture.allOf is Promise.all; supplyAsync uses ForkJoinPool.
        //   Java 21+ virtual threads improve blocking I/O; CompletableFuture is still standard.
    }
}