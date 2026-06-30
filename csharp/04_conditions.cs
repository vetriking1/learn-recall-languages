// ============================================================
// Topic:  Conditions
// Summary: if / else if / else, ternary, truthiness, switch.
// Run:     dotnet script csharp/04_conditions.cs
// ============================================================

using System;

// ----- 1. Basic if / else if / else (needs ( ) around test and { } block) -----
int age = 20;
if (age < 13)
{
    Console.WriteLine("child");
}
else if (age < 18)          // Python: elif
{
    Console.WriteLine("teen");
}
else
{
    Console.WriteLine("adult");
}
// Output: adult

// ----- 2. Ternary (cond ? a : b) -----
string status = age >= 18 ? "pass" : "fail";
Console.WriteLine(status); // Output: pass
// Python: status = "pass" if age >= 18 else "fail"   (word order reversed)

// ----- 3. Truthiness — ONLY bool works in if (unlike Python/TS) -----
// C# requires an explicit bool; no implicit truthiness from 0, "", [], etc.
int[] emptyArr = [];
if (emptyArr.Length == 0)
{
    Console.WriteLine("empty array has Length 0"); // Output: empty array has Length 0
}
// if (emptyArr) { }  // ❌ ERROR: cannot use int[] as bool
string greeting = "hello";
if (greeting.Length > 0)
    Console.WriteLine("non-empty string is truthy when checked"); // Output: ...truthy when checked

// ----- 4. Combining conditions -----
int temp = 25;
if (temp > 20 && temp < 30)
{
    Console.WriteLine("comfortable"); // Output: comfortable
}

// ----- 5. switch (Python 3.10+: match/case) -----
string command = "start";
switch (command)
{
    case "start":
        Console.WriteLine("starting"); // Output: starting
        break;                           // ⚠ don't forget break (Python match has no fall-through)
    case "stop":
        Console.WriteLine("stopping");
        break;
    default:
        Console.WriteLine("unknown");
        break;
}

// ----- 6. switch expression (modern C# concise form) -----
string label = command switch
{
    "start" => "go",
    "stop" => "halt",
    _ => "?"                           // default (Python match: case _)
};
Console.WriteLine(label); // Output: go

// Cross-language note:
//   C# needs ( ) around the condition and { } for blocks; Python uses indentation.
//   Ternary order: C#/TS `cond ? a : b`  vs  Python `a if cond else b`.
//   C# has NO implicit truthiness — check `.Length == 0`, `== null`, etc. explicitly.
//   Empty [] is not falsy in C# (you can't even put it in an if); Python treats [] as falsy.