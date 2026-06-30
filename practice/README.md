# Practice Problems

Classic beginner exercises implemented in all six workspace languages —
**Python · TypeScript · C# · Rust · C++ · Java**. Every language produces the
**same output** for the same problem, so you can read them side by side.

Files are grouped by category (one file per category per language), and each
problem is a numbered section inside the file.

## Problems

| Category   | File          | Problems |
|------------|---------------|----------|
| Arrays     | `arrays.*`    | 1. max & min · 2. sum & average · 3. in-place reverse · 4. remove duplicates (sorted) |
| Strings    | `strings.*`   | 1. reverse (no built-in) · 2. palindrome (ignore case/spaces) · 3. count vowels/consonants/special |
| Numbers    | `numbers.*`   | 1. prime check · 2. multiplication table · 3. GCD (Euclidean) |
| Patterns   | `patterns.*`  | 1. right-angled triangle · 2. centered pyramid |
| Algorithms | `algorithms.*`| 1. linear search · 2. binary search · 3. Fibonacci (iterative + recursive) |
| Data Structures | `data_structures.*` | 1. word frequency · 2. two-sum · 3. dedupe (preserve order) · 4. valid parentheses · 5. merge two sorted · 6. group anagrams |

## Layout

```
practice/
├── python/      *.py
├── typescript/  *.ts  (+ tsconfig.json)
├── csharp/      *.cs
├── rust/        *.rs
├── cpp/         *.cpp
└── java/        *.java
```

## How to run (example: the Arrays file)

```bash
# Python (3.10+)
python practice/python/arrays.py

# TypeScript (uses the typescript/ project's ts-node)
cd typescript && npx ts-node --project ../practice/typescript/tsconfig.json ../practice/typescript/arrays.ts

# C# (requires dotnet-script)
dotnet script practice/csharp/arrays.cs

# Rust (compile then run)
rustc practice/rust/arrays.rs -o practice/rust/arrays && practice/rust/arrays

# C++ (requires g++)
g++ -std=c++17 practice/cpp/arrays.cpp -o practice/cpp/arrays && practice/cpp/arrays

# Java (11+, single-file launch — no separate compile step)
java practice/java/arrays.java
```

Swap `arrays` for `strings`, `numbers`, `patterns`, `algorithms`, or
`data_structures`. The exact
run command is also in the header comment of every source file.

> All implementations were run and their output verified to match across
> languages. See [../AGENTS.md](../AGENTS.md) for workspace conventions.
