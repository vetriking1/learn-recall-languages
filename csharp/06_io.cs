// ============================================================
// Topic:  Console Output & Input
// Summary: Console.Write/WriteLine, interpolation, ReadLine.
// Run:     dotnet script csharp/06_io.cs
// Note:    Reads lines from the keyboard. To pipe input:
//          echo Vetri | dotnet script csharp/06_io.cs
//          (PowerShell: "Vetri`n5" | dotnet script csharp/06_io.cs)
// ============================================================

#nullable enable

using System;
using System.Globalization;

// ----- 1. Basic output -----
Console.WriteLine("Hello, world");        // Output: Hello, world

// ----- 2. Multiple values (space-separated, like Python print) -----
Console.WriteLine(string.Join(" ", "a", "b", "c")); // Output: a b c  (Python print sep=" ")

// ----- 3. Template literals (Python: f-strings) -----
string name = "Vetri";
int age = 22;
Console.WriteLine($"{name} is {age}");    // Output: Vetri is 22
Console.WriteLine(3.14159.ToString("F2", CultureInfo.InvariantCulture)); // Output: 3.14

// ----- 4. Output without a newline -----
Console.Write("no newline ");             // (Python: print(..., end=""))
Console.WriteLine("next");                // Output: no newline next

// ----- 5. Other output channels -----
Console.Error.WriteLine("this goes to stderr"); // for errors (Python: file=sys.stderr)

// ----- 6. Reading input from the keyboard -----
// Python equivalent is the one-liner: input("Enter your name: ")
Console.Write("Enter your name: ");
string? userName = Console.ReadLine();
Console.WriteLine($"Hi {userName}!");
// Example (input "Vetri"): Hi Vetri!

// ----- 7. Converting input to a number -----
// ReadLine ALWAYS returns a string — cast it (like Python int()).
Console.Write("Enter a number: ");
string? raw = Console.ReadLine();
int number = int.Parse(raw ?? "0");       // "5" -> 5
Console.WriteLine($"Doubled: {number * 2}");
// Example (input "5"): Doubled: 10

// Cross-language note:
//   Console.WriteLine()  == Python print()       == TS console.log()
//   Console.Write()      == Python print(..., end="") == TS process.stdout.write
//   Console.ReadLine()   == Python input()       — ALWAYS returns a string,
//                          so cast with int.Parse()/double.Parse() for math.
//   C# ReadLine blocks synchronously (like Python); TS Node readline is callback-based.