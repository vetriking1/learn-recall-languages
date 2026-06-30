// ============================================================
// Topic:  Loops
// Summary: for, foreach, while, break/continue, LINQ transforms.
// Run:     dotnet script csharp/05_loops.cs
// ============================================================

using System;
using System.Collections.Generic;
using System.Linq;

// ----- 1. for over a range -----
// Enumerable.Range(start, count) -> start..start+count-1   |  Python: range(3)
for (int i = 0; i < 3; i++)
    Console.Write($"{i} ");              // Output: 0 1 2
Console.WriteLine();

// range with step (Python: range(2, 11, 2))
for (int i = 2; i < 11; i += 2)
    Console.Write($"{i} ");              // Output: 2 4 6 8 10
Console.WriteLine();

// ----- 2. foreach over a collection (Python: for x in coll; TS: for..of) -----
var fruits = new List<string> { "apple", "banana", "cherry" };
foreach (var fruit in fruits)
    Console.Write($"{fruit} ");          // Output: apple banana cherry
Console.WriteLine();

// ----- 3. index + value (Python: enumerate; TS: arr.entries()) -----
for (int index = 0; index < fruits.Count; index++)
    Console.Write($"{index}:{fruits[index]} "); // Output: 0:apple 1:banana 2:cherry
Console.WriteLine();

// ----- 4. while loop -----
int n = 3;
while (n > 0)
{
    Console.Write($"{n} ");
    n--;
}
Console.WriteLine();                     // Output: 3 2 1

// ----- 5. break and continue -----
for (int i = 0; i < 10; i++)
{
    if (i == 3) continue;                // skip 3
    if (i == 6) break;                   // stop at 6
    Console.Write($"{i} ");              // Output: 0 1 2 4 5
}
Console.WriteLine();

// ----- 6. No for-else (Python-only: else runs if loop didn't break) -----
// C# has no equivalent — use a flag variable if you need that pattern.

// ----- 7. LINQ transforms (Python: list comprehension; TS: map/filter) -----
var squares = Enumerable.Range(0, 5).Select(x => x * x).ToList();
Console.WriteLine($"[{string.Join(", ", squares)}]"); // Output: [0, 1, 4, 9, 16]
var evens = Enumerable.Range(0, 10).Where(x => x % 2 == 0).ToList();
Console.WriteLine($"[{string.Join(", ", evens)}]");   // Output: [0, 2, 4, 6, 8]

// Cross-language note:
//   C# `foreach (var x in coll)` == Python `for x in coll` == TS `for (const x of coll)`.
//   C# uses a C-style `for` counter or `Enumerable.Range`; Python uses `range()`.
//   C# has `i++`; Python has no ++ (use i += 1).
//   C# LINQ `.Select/.Where` ≈ Python comprehensions ≈ TS `.map/.filter`.