// ============================================================
// Topic:  Strings  (FOCUS: methods & operations)
// Summary: Length, indexing, slicing, case, search, split/join, format.
// Run:     dotnet script csharp/08_strings.cs
//
// KEY DIFFERENCE the user cares about:
//   C#: s.Length, s.ToLower()     |   Python: len(s), s.lower()
//   C#: s.ToLower()               |   TS: s.toLowerCase()
// ============================================================

using System;
using System.Linq;

string ToTitleCase(string text) =>
    string.Join(' ', text.Split(' ').Select(w =>
        w.Length > 0 ? char.ToUpper(w[0]) + w[1..].ToLower() : w));

string s = "Hello, World";

// ----- 1. Length (a PROPERTY, no parentheses; Python: len(s)) -----
Console.WriteLine(s.Length);              // 12   ⚠ s.Length NOT len(s)

// ----- 2. Indexing & negative indexing (C# 8+: ^1 means last) -----
Console.WriteLine(s[0]);                  // H     | Python: s[0]   | TS: s[0]
Console.WriteLine(s[^1]);                 // d     | Python: s[-1]  | TS: s.at(-1)

// ----- 3. Slicing -> s[start..stop] or Substring  (Python: s[start:stop]) -----
Console.WriteLine(s[0..5]);               // Hello
Console.WriteLine(s[7..]);                // World
Console.WriteLine(s[..5]);                // Hello
Console.WriteLine(new string(s.Reverse().ToArray())); // dlroW ,olleH (reverse; Python: s[::-1])

// ----- 4. Case methods -----
Console.WriteLine(s.ToLower());           // hello, world   | Python: s.lower()   | TS: s.toLowerCase()
Console.WriteLine(s.ToUpper());           // HELLO, WORLD   | Python: s.upper()   | TS: s.toUpperCase()
Console.WriteLine(ToTitleCase("hi there")); // Hi There    (Python: .title())

// ----- 5. Search / test -----
Console.WriteLine(s.IndexOf("World"));    // 7   (-1 if missing) | Python: s.find() | TS: s.indexOf()
Console.WriteLine(s.Contains("World"));   // True              | Python: "World" in s | TS: s.includes()
Console.WriteLine(s.StartsWith("Hello")); // True              | Python: s.startswith()
Console.WriteLine(s.EndsWith("World"));   // True              | Python: s.endswith()
Console.WriteLine(s.Count(c => c == 'l')); // 3   count occurrences

// ----- 6. Modify (strings are IMMUTABLE; methods return NEW strings) -----
Console.WriteLine(s.Replace("World", "Vetri")); // Hello, Vetri | Python/TS: s.replace(...)
Console.WriteLine("  pad  ".Trim());              // pad          | Python: s.strip() | TS: s.trim()
Console.WriteLine(string.Join(", ", "a,b,c".Split(','))); // a, b, c | Python: split returns list
Console.WriteLine(string.Join("-", new[] { "a", "b", "c" })); // a-b-c | Python: "-".join([...])
Console.WriteLine("5".PadLeft(3, '0'));          // 005          | Python: "5".zfill(3) | TS: padStart

// ----- 7. Formatting (interpolated strings; Python: f-strings; TS: template literals) -----
string name = "Vetri";
int age = 22;
Console.WriteLine($"{name} is {age}");    // Vetri is 22
Console.WriteLine(string.Format("{0} is {1}", name, age)); // Vetri is 22 (older style)

// ----- 8. Char <-> code -----
Console.WriteLine((int)'A');              // 65   | Python: ord("A") | TS: "A".charCodeAt(0)
Console.WriteLine((char)66);              // B    | Python: chr(66)  | TS: String.fromCharCode(66)

// ----- Quick reference table (C# -> Python/TS) -----
// s.Length            -> len(s) / s.length
// s.ToLower()         -> s.lower() / s.toLowerCase()
// s.ToUpper()         -> s.upper() / s.toUpperCase()
// s.IndexOf(x)        -> s.find(x) / s.indexOf(x)
// s.Contains(x)       -> x in s / s.includes(x)
// s.Trim()            -> s.strip() / s.trim()
// s.Replace(a,b)      -> s.replace(a,b) / s.replaceAll(a,b)
// s.Split(",")        -> s.split(",") / s.split(",")
// string.Join("-",a)  -> "-".join(a) / a.join("-")
// s[a..b]             -> s[a:b] / s.slice(a,b)