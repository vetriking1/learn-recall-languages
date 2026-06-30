# AllLanguages — Learn & Recall

A hands-on reference workspace for learning programming concepts across
languages and **recalling** the exact syntax/method that differs between them.

**Languages:** Python · TypeScript · C# · Rust · C++ · Java

## Layout

```
AllLanguages/
├── README.md         ← you are here
├── AGENTS.md         ← how the workspace is structured & extended (for humans + AI agents)
├── python/           ← runnable .py files, one per topic
├── typescript/       ← runnable .ts files, one per topic (+ package.json, tsconfig.json)
├── csharp/           ← runnable .cs files, one per topic (top-level statements, dotnet-script)
├── rust/             ← runnable .rs files, one per topic (single-file rustc compilation)
├── cpp/              ← runnable .cpp files, one per topic (g++ -std=c++17)
├── java/             ← runnable .java files, one per topic (java 11+ single-file launch)
├── practice/         ← classic exercises (arrays, strings, numbers, patterns, algorithms) in all 6 languages
└── docs/             ← open index.html in a browser: side-by-side comparison tables
```

Each topic exists as a numbered file per language plus one comparison page in `docs/`:

| #  | Topic         | Python                   | TypeScript                   | C#                        | Rust                    | C++                     | Java                     | Visual                  |
|----|---------------|--------------------------|------------------------------|---------------------------|-------------------------|-------------------------|--------------------------|-------------------------|
| 01 | Variables     | `python/01_variables.py` | `typescript/01_variables.ts` | `csharp/01_variables.cs`  | `rust/01_variables.rs`  | `cpp/01_variables.cpp`  | `java/01_variables.java`  | `docs/variables.html`   |
| 02 | Data Types    | `python/02_datatypes.py` | `typescript/02_datatypes.ts` | `csharp/02_datatypes.cs`  | `rust/02_datatypes.rs`  | `cpp/02_datatypes.cpp`  | `java/02_datatypes.java`  | `docs/datatypes.html`   |
| 03 | Operators     | `python/03_operators.py` | `typescript/03_operators.ts` | `csharp/03_operators.cs`  | `rust/03_operators.rs`  | `cpp/03_operators.cpp`  | `java/03_operators.java`  | `docs/operators.html`   |
| 04 | Conditions    | `python/04_conditions.py`| `typescript/04_conditions.ts`| `csharp/04_conditions.cs` | `rust/04_conditions.rs` | `cpp/04_conditions.cpp` | `java/04_conditions.java` | `docs/conditions.html`  |
| 05 | Loops         | `python/05_loops.py`     | `typescript/05_loops.ts`     | `csharp/05_loops.cs`      | `rust/05_loops.rs`      | `cpp/05_loops.cpp`      | `java/05_loops.java`      | `docs/loops.html`       |
| 06 | Input/Output  | `python/06_io.py`        | `typescript/06_io.ts`        | `csharp/06_io.cs`         | `rust/06_io.rs`         | `cpp/06_io.cpp`         | `java/06_io.java`         | `docs/io.html`          |
| 07 | Functions     | `python/07_functions.py` | `typescript/07_functions.ts` | `csharp/07_functions.cs`  | `rust/07_functions.rs`  | `cpp/07_functions.cpp`  | `java/07_functions.java`  | `docs/functions.html`   |
| 08 | Strings ★     | `python/08_strings.py`   | `typescript/08_strings.ts`   | `csharp/08_strings.cs`    | `rust/08_strings.rs`    | `cpp/08_strings.cpp`    | `java/08_strings.java`    | `docs/strings.html`     |
| 09 | Arrays/Lists ★| `python/09_arrays.py`    | `typescript/09_arrays.ts`    | `csharp/09_arrays.cs`     | `rust/09_arrays.rs`     | `cpp/09_arrays.cpp`     | `java/09_arrays.java`     | `docs/arrays.html`      |

★ = method-focus topics (the data-type methods that differ most between languages).

### Data Structures (15)

| #  | Topic            | Python                            | TypeScript                            | C#                                 | Rust                              | C++                               | Java                               | Visual                       |
|----|------------------|-----------------------------------|---------------------------------------|------------------------------------|-----------------------------------|-----------------------------------|------------------------------------|------------------------------|
| 15 | Data Structures ★| `python/15_data_structures.py`    | `typescript/15_data_structures.ts`    | `csharp/15_data_structures.cs`     | `rust/15_data_structures.rs`      | `cpp/15_data_structures.cpp`      | `java/15_data_structures.java`     | `docs/data_structures.html`  |

Maps, sets, stack, queue, heap, and tuples/pairs — all in one file per language.

### Async / Await (16)

| #  | Topic       | Python                      | TypeScript                      | C#                           | Rust                         | C++                          | Java                          | Visual                  |
|----|-------------|-----------------------------|---------------------------------|------------------------------|------------------------------|------------------------------|-------------------------------|-------------------------|
| 16 | Async/Await ★| `python/16_async_await.py`  | `typescript/16_async_await.ts`  | `csharp/16_async_await.cs`   | `rust/16_async_await.rs`     | `cpp/16_async_await.cpp`     | `java/16_async_await.java`    | `docs/async_await.html` |

Non-blocking execution: async functions, await, parallel tasks, delays, errors.

### Threads & Processes (17)

| #  | Topic              | Python                                  | TypeScript                                  | C#                                       | Rust                                     | C++                                      | Java                                      | Visual                            |
|----|--------------------|-----------------------------------------|---------------------------------------------|------------------------------------------|------------------------------------------|------------------------------------------|-------------------------------------------|-----------------------------------|
| 17 | Threads/Processes ★| `python/17_threads_and_processes.py`    | `typescript/17_threads_and_processes.ts`    | `csharp/17_threads_and_processes.cs`     | `rust/17_threads_and_processes.rs`       | `cpp/17_threads_and_processes.cpp`       | `java/17_threads_and_processes.java`      | `docs/threads_and_processes.html` |

Multithreading (spawn, join, mutex) and multiprocessing (separate child process).

### Higher Concepts (18–20)

| #  | Topic           | Python                      | TypeScript                      | C#                           | Rust                         | C++                          | Java                          | Visual                    |
|----|-----------------|-----------------------------|---------------------------------|------------------------------|------------------------------|------------------------------|-------------------------------|---------------------------|
| 18 | Error Handling ★| `python/18_error_handling.py`| `typescript/18_error_handling.ts`| `csharp/18_error_handling.cs`| `rust/18_error_handling.rs`  | `cpp/18_error_handling.cpp`  | `java/18_error_handling.java` | `docs/error_handling.html`|
| 19 | Generics ★      | `python/19_generics.py`     | `typescript/19_generics.ts`     | `csharp/19_generics.cs`      | `rust/19_generics.rs`        | `cpp/19_generics.cpp`        | `java/19_generics.java`       | `docs/generics.html`      |
| 20 | Modules ★       | `python/20_modules.py`      | `typescript/20_modules.ts`      | `csharp/20_modules.cs`       | `rust/20_modules.rs`           | `cpp/20_modules.cpp`           | `java/20_modules.java`        | `docs/modules.html`       |

### Language-Specific Features (21)

| #  | Topic              | Python                           | TypeScript                           | C#                                | Rust                              | C++                               | Java                               | Visual                         |
|----|--------------------|----------------------------------|--------------------------------------|-----------------------------------|-----------------------------------|-----------------------------------|------------------------------------|--------------------------------|
| 21 | Language Features ★| `python/21_language_features.py` | `typescript/21_language_features.ts` | `csharp/21_language_features.cs`  | `rust/21_language_features.rs`    | `cpp/21_language_features.cpp`    | `java/21_language_features.java`   | `docs/language_features.html`  |

Six idioms per language that don't map 1:1 across the grid (comprehensions, LINQ, ownership, etc.).

### Object-Oriented Programming (10–14)

| #  | Topic         | Python                       | TypeScript                       | C#                            | Rust                        | C++                         | Java                          | Visual                     |
|----|---------------|------------------------------|----------------------------------|-------------------------------|-----------------------------|-----------------------------|-------------------------------|----------------------------|
| 10 | Classes       | `python/10_classes.py`       | `typescript/10_classes.ts`       | `csharp/10_classes.cs`        | `rust/10_classes.rs`        | `cpp/10_classes.cpp`        | `java/10_classes.java`        | `docs/classes.html`        |
| 11 | Encapsulation | `python/11_encapsulation.py` | `typescript/11_encapsulation.ts` | `csharp/11_encapsulation.cs`  | `rust/11_encapsulation.rs`  | `cpp/11_encapsulation.cpp`  | `java/11_encapsulation.java`  | `docs/encapsulation.html`  |
| 12 | Inheritance   | `python/12_inheritance.py`   | `typescript/12_inheritance.ts`   | `csharp/12_inheritance.cs`    | `rust/12_inheritance.rs`    | `cpp/12_inheritance.cpp`    | `java/12_inheritance.java`    | `docs/inheritance.html`    |
| 13 | Polymorphism  | `python/13_polymorphism.py`  | `typescript/13_polymorphism.ts`  | `csharp/13_polymorphism.cs`   | `rust/13_polymorphism.rs`   | `cpp/13_polymorphism.cpp`   | `java/13_polymorphism.java`   | `docs/polymorphism.html`   |
| 14 | Abstraction   | `python/14_abstraction.py`   | `typescript/14_abstraction.ts`   | `csharp/14_abstraction.cs`    | `rust/14_abstraction.rs`    | `cpp/14_abstraction.cpp`    | `java/14_abstraction.java`    | `docs/abstraction.html`    |

> Rust has no classes or inheritance — these files show the idiomatic equivalents
> (`struct` + `impl`, module privacy, and `trait`s with default methods).

## How to run

**Python** (3.10+):

```bash
python python/08_strings.py
```

**TypeScript** (one-time install, then run any file):

```bash
cd typescript
npm install
npx ts-node 08_strings.ts
```

**C#** (install dotnet-script once, then run any file):

```bash
dotnet tool install -g dotnet-script
dotnet script csharp/08_strings.cs
```

**Files that read input** (06) — feed them via a pipe:

```bash
echo "Vetri" | python python/06_io.py
echo "Vetri" | npx ts-node typescript/06_io.ts   # run from repo root or adjust path
echo "Vetri" | dotnet script csharp/06_io.cs
```

**Rust** (compile then run):

```bash
rustc rust/08_strings.rs -o rust/08_strings && rust/08_strings
echo "Vetri" | rust/06_io
```

**C++** (compile then run):

```bash
g++ -std=c++17 cpp/08_strings.cpp -o cpp/08_strings && cpp/08_strings
echo "Vetri" | cpp/06_io
```

**Java** (11+, single-file source launch — no separate compile step):

```bash
java java/08_strings.java
printf "Vetri\n5\n" | java java/06_io.java
```

**The visual comparison** — just open `docs/index.html` in any browser
(double-click; no build step).

**Practice problems** — classic exercises (arrays, strings, numbers,
patterns, algorithms, data structures) implemented in all six languages with
matching output. See [practice/README.md](practice/README.md).

## Roadmap

1. ✅ Basics for Python + TypeScript (this pass)
2. ✅ Add C# columns to every topic
3. ✅ Add Rust columns to every topic
4. ✅ Add C++ columns to every topic
5. ✅ Add Java columns to every topic — all six languages now cover every basics topic
6. ✅ OOP across all six languages: classes, encapsulation, inheritance, polymorphism, abstraction (10–14)
7. ✅ Data structures: maps, sets, stack, queue, heap, tuples (15) + practice exercises
8. ✅ Async / await (16) across all six languages
9. ✅ Multithreading & multiprocessing (17) across all six languages
10. ✅ Higher concepts: error handling (18), generics (19), modules (20)
11. ✅ Language-specific features (21) — six idioms per language
8. ⬜ Language-specific features

See [AGENTS.md](AGENTS.md) before adding anything — it documents the conventions
that keep all files consistent.
