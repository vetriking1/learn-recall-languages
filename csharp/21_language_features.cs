// ============================================================
// Topic:  Language Features
// Summary: LINQ, auto-properties, pattern matching, interpolation,
//          nullable reference types, records with expressions.
// Run:     dotnet script csharp/21_language_features.cs
//
// KEY DIFFERENCES:
//   C#:     LINQ, records, pattern matching, nullable ref types
//   Python: list comprehensions, dataclasses, match/case (3.10+)
//   TS/JS:  Array.map/filter, optional chaining ?., template literals
//   Rust:   iterators, struct + derive, match, Option/?
//   Java:   Streams, records (16+), switch expressions, Optional
// ============================================================

#nullable enable

using System;
using System.Linq;

// ----- 1. LINQ — query syntax / method chain on IEnumerable -----
var nums = new[] { 1, 2, 3 };
var doubled = nums.Select(n => n * 2);                 // Select    | map each element
Console.WriteLine($"linq: {string.Join(" ", doubled)}"); // linq: 2 4 6

// ----- 2. Auto-properties — compiler-generated backing field -----
class Person
{
    public string Name { get; set; } = "Vetri";      // auto-prop | get/set without field
}
var person = new Person();
Console.WriteLine($"prop: {person.Name}");           // prop: Vetri

// ----- 3. Pattern matching switch — type and relational patterns -----
object value = 42;
string label = value switch
{
    int n when n > 10 => "big",                      // when      | guard on pattern
    int n => "small",
    _ => "other"
};
Console.WriteLine($"match: {label}");              // match: big

// ----- 4. String interpolation — $ prefix embeds expressions -----
string name = "Vetri";
Console.WriteLine($"fmt: hi {name}");                // fmt: hi Vetri

// ----- 5. Nullable reference types + null-conditional ?. -----
string? text = null;                                 // string?   | nullable annotation
int length = text?.Length ?? 0;                      // ?. ??     | null-safe access, default 0
Console.WriteLine($"nullsafe: {length}");            // nullsafe: 0

// ----- 6. record + with expression — immutable copy with changes -----
record Player(string Name, int Score);               // record    | positional, value equality
var original = new Player("Bob", 50);
var updated = original with { Name = "Alice", Score = 100 }; // with | non-destructive mutation
Console.WriteLine($"record: {updated.Name} score={updated.Score}"); // record: Alice score=100

// Cross-language note:
//   LINQ ≈ Python comprehensions / Rust iterators / Java Streams — lazy until enumerated.
//   records ≈ Python @dataclass / TS readonly tuples — structural equality by default.
//   with expressions ≈ spread copy ({ ...obj, name: "Alice" }) without mutating the original.
//   Nullable reference types are compile-time hints — runtime null still possible without checks.
//   Pattern matching switch subsumes classic switch; order matters when patterns overlap.