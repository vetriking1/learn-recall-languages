// ============================================================
// Topic:  Functions
// Summary: Methods, lambdas, defaults, params, return tuples.
// Run:     dotnet script csharp/07_functions.cs
// ============================================================

using System;
using System.Collections.Generic;
using System.Linq;

// ----- 1. Basic function (local function with typed params + return) -----
string Greet(string name) => $"Hello, {name}";
Console.WriteLine(Greet("Vetri")); // Output: Hello, Vetri

// ----- 2. Lambda (Python: lambda; TS: arrow function) -----
Func<int, int, int> add = (a, b) => a + b;
Console.WriteLine(add(2, 3)); // Output: 5

// ----- 3. Default parameters -----
int Power(int baseVal, int exp = 2) => (int)Math.Pow(baseVal, exp);
Console.WriteLine(Power(5));    // Output: 25
Console.WriteLine(Power(5, 3)); // Output: 125

// ----- 4. Optional parameters (nullable — Python uses =None defaults) -----
string MakeUser(string name, int? age = null) => $"{name}/{age?.ToString() ?? "unknown"}";
Console.WriteLine(MakeUser("Vetri"));     // Output: Vetri/unknown
Console.WriteLine(MakeUser("Vetri", 22)); // Output: Vetri/22

// ----- 5. params -> variable positional args (Python: *args; TS: ...rest) -----
int Total(params int[] numbers) => numbers.Sum();
Console.WriteLine(Total(1, 2, 3, 4)); // Output: 10

// ----- 6. Named arguments (call by name, any order — like Python) -----
string MakeProfile(string name, int age) => $"{name}/{age}";
Console.WriteLine(MakeProfile(age: 22, name: "Vetri")); // Output: Vetri/22

// ----- 7. Returning multiple values via tuple (Python: tuple; TS: array) -----
(int low, int high) MinMax(int[] nums) => (nums.Min(), nums.Max());
var (low, high) = MinMax(new[] { 4, 1, 9, 2 });
Console.WriteLine($"{low} {high}"); // Output: 1 9

// ----- 8. Functions as values / callbacks -----
var nums = new List<int> { 3, 1, 2 };
Console.WriteLine($"[{string.Join(", ", nums.OrderByDescending(x => x))}]"); // Output: [3, 2, 1]

// Cross-language note:
//   C# `string F(string x) => ...`  == Python `def f(x):`  == TS `function f(x) {}`
//   C# `(x) => x * x`               == Python `lambda x: x*x`  == TS `(x) => x*x`
//   C# returns ValueTuple `(a, b)`; Python returns a real tuple; TS returns an array.
//   Params are typed in C# (string name) — Python hints are optional; TS enforces types.