// ============================================================
// Topic:  Data Types
// Summary: Primitives, typeof, null, collections, casting.
// Run:     dotnet script csharp/02_datatypes.cs
// ============================================================

#nullable enable

using System;
using System.Collections.Generic;

// ----- 1. Core scalar types (int and double are separate, like Python) -----
int anInt = 42;              // int          (TS: number — one type for all numbers)
double aFloat = 3.14;        // double       (TS: number)
string aStr = "hello";       // string       (TS: string)
bool aBool = true;           // bool         (TS: boolean; Python: True/False)
string? nothing = null;      // nullable     (TS: null; Python: None)
Console.WriteLine($"{anInt} {aFloat} {aStr} {aBool} {nothing}");
// Output: 42 3.14 hello True

// ----- 2. Checking a type -> typeof / GetType()  (Python: type(x); TS: typeof x) -----
Console.WriteLine(typeof(int));           // Output: System.Int32
Console.WriteLine(typeof(string));        // Output: System.String
object boxed = aBool;
Console.WriteLine(boxed is bool);         // Output: True   (pattern-style type check)

// ----- 3. Collection types -----
var aList = new List<int> { 1, 2, 3 };           // List   (Python: list; TS: number[])
var aTuple = (1, 2, 3);                          // tuple  (Python: tuple; TS: [number, number, number])
var aDict = new Dictionary<string, string> { ["k"] = "v" }; // dict (Python: dict; TS: object/Map)
var aSet = new HashSet<int> { 1, 2, 3 };         // set    (Python: set; TS: Set)
Console.WriteLine($"{string.Join(", ", aList)} {aTuple} k={aDict["k"]} {{{string.Join(", ", aSet)}}}");
// Output: 1, 2, 3 (1, 2, 3) k=v {1, 2, 3}

// ----- 4. Conversion / casting -----
Console.WriteLine(int.Parse("10") + 5);           // str -> int    Output: 15
Console.WriteLine(10.ToString() + "5");           // int -> str    Output: 105
Console.WriteLine(double.Parse("3.5"));           // str -> double Output: 3.5
Console.WriteLine($"{Convert.ToBoolean(0)} {!string.IsNullOrEmpty("")} {Convert.ToBoolean(1)}");
// Output: False False True   (C# has no bool(""); use !string.IsNullOrEmpty(s) instead)

// ----- 5. Numeric detail (C# splits int vs double, like Python) -----
Console.WriteLine(7 / 2);              // int division when both int   Output: 3
Console.WriteLine(7 / 2.0);            // float division               Output: 3.5
Console.WriteLine(Math.Pow(2, 10));    // power (no ** operator)       Output: 1024
Console.WriteLine(10 % 3);             // modulo                       Output: 1

// ----- 6. Nullable value types (C# has one "empty" for references; value types need ?) -----
int? maybe = null;           // nullable int — can hold null or a number
int definite = 0;              // plain int — cannot be null
Console.WriteLine($"{maybe} {definite}"); // Output:  (blank) 0

// Cross-language note:
//   C# splits int vs double (like Python). TS has only `number` (64-bit float).
//   C# null ≈ TS null ≈ Python None. C# value types (int, bool) need `?` to be nullable.
//   C# has no undefined — only null (TS has both null and undefined).