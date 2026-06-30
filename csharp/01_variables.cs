// ============================================================
// Topic:  Variables
// Summary: var, explicit types, const, naming, static typing.
// Run:     dotnet script csharp/01_variables.cs
// ============================================================

using System;

// ----- 1. var vs explicit type (prefer var when the type is obvious) -----
var name = "Vetri";       // inferred as string   (Python: name = "Vetri")
int age = 22;               // explicit type        (TS: let age: number = 22)
Console.WriteLine($"{name} {age}"); // Output: Vetri 22

// ----- 2. const vs let (const is compile-time constant) -----
const double PI = 3.14159;  // cannot reassign   (TS: const PI = 3.14159)
int score = 10;
score = 20;                 // OK — regular variable is mutable
Console.WriteLine(score);   // Output: 20
// PI = 3.0;  // ❌ ERROR: const cannot be reassigned (Python has no real const)

// ----- 3. Multiple assignment via tuples -----
(int x, int y, int z) = (1, 2, 3);
int a = 0, b = 0, c = 0;    // all initialized to 0
Console.WriteLine($"{x} {y} {z} {a} {b} {c}"); // Output: 1 2 3 0 0 0

// ----- 4. Swapping (tuple deconstruction) -----
(x, y) = (y, x);            // (Python: x, y = y, x)   (TS: [x, y] = [y, x])
Console.WriteLine($"{x} {y}"); // Output: 2 1

// ----- 5. Type annotations are enforced at compile time -----
string username = "abc";
int count = 5;
bool active = true;
Console.WriteLine($"{username} {count} {active}"); // Output: abc 5 True

// ----- 6. Naming: camelCase for locals (TS convention; Python uses snake_case) -----
double totalPrice = 99.5;
Console.WriteLine(totalPrice); // Output: 99.5

// ----- 7. Static typing (no silent type change on rebind) -----
object thing = 5;
thing = "now a string";     // allowed via object   (Python allows this on any variable)
Console.WriteLine(thing);   // Output: now a string
// int n = 5; n = "text";   // ❌ ERROR: cannot assign string to int (TS would also error)

// Cross-language note:
//   C#:      var name = "Vetri";  or  string name = "Vetri";
//   TS:      let name = "Vetri";  or  const name = "Vetri";
//   Python:  name = "Vetri"        // no keyword, no real const
//   C# is statically typed like TS; Python rebinds freely (unless you use type hints).