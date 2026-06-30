// ============================================================
// Topic:  Operators
// Summary: Arithmetic, comparison, logical, increment, null-coalescing.
// Run:     dotnet script csharp/03_operators.cs
// ============================================================

#nullable enable

using System;
using System.Collections.Generic;

// ----- 1. Arithmetic -----
Console.WriteLine(5 + 2);              // 7
Console.WriteLine(5 - 2);              // 3
Console.WriteLine(5 * 2);              // 10
Console.WriteLine(5 / 2);              // 2     int/int truncates (Python 5/2 is 3.5!)
Console.WriteLine(5 / 2.0);            // 2.5   float division (Python: 5 / 2)
Console.WriteLine(5 % 2);              // 1
Console.WriteLine(Math.Pow(5, 2));       // 25    (Python/TS: 5 ** 2)

// ----- 2. Comparison (== compares values; no === in C#) -----
int five = 5, three = 3;
Console.WriteLine(five == 5);          // True   (TS strict: ===; Python: ==)
Console.WriteLine(five != three);      // True   (Python: !=)
Console.WriteLine($"{"5" == "5"} {five == 5}"); // True True — string "5" != int 5 at compile time
// Console.WriteLine("5" == 5);        // ❌ ERROR: cannot compare string to int (unlike TS loose ==)

// ----- 3. Logical (symbols, like TS; Python uses and/or/not) -----
Console.WriteLine(true && false);      // False  (Python: and)
Console.WriteLine(true || false);      // True   (Python: or)
Console.WriteLine(!true);              // False  (Python: not)

// ----- 4. Increment / decrement (Python has NEITHER) -----
int n = 10;
n++;                                   // 11   (Python: n += 1)
n--;                                   // 10
Console.WriteLine(n);                  // Output: 10

// ----- 5. Augmented assignment -----
int m = 10;
m += 5;                                // 15
m *= 2;                                // 30
Console.WriteLine(m);                  // Output: 30

// ----- 6. Chained comparison needs && (Python allows 1 < x < 10) -----
int x = 5;
Console.WriteLine(1 < x && x < 10);    // True   (Python: 1 < x < 10)

// ----- 7. Null-coalescing & null-conditional (like TS ?? and ?.) -----
string? input = null;
Console.WriteLine(input ?? "default"); // Output: default  (TS: input ?? "default")
string? nickname = null;
Console.WriteLine(nickname?.Length);   // Output: blank (null) — ?. safe access when null

// ----- 8. Membership uses methods, not an operator (Python has `in`) -----
var list = new List<int> { 1, 2, 3 };
Console.WriteLine(list.Contains(3));   // True   (Python: 3 in [1,2,3])
Console.WriteLine("cat".Contains("a")); // True  (Python: "a" in "cat")

// Cross-language note:
//   Equality: C# `==` compares values with type safety (no loose coercion like TS `==`).
//   Division: C# `5 / 2` is 2 (ints); Python `5 / 2` is 3.5. Use `5 / 2.0` for float.
//   Increment: C# `i++` exists; Python has no ++ (use i += 1).
//   Power: C# uses Math.Pow(a, b); Python/TS use a ** b.