// ============================================================
// Topic:  Modules & Namespaces
// Summary: Namespaces, using System.Math, using alias, block namespace.
// Run:     dotnet script csharp/20_modules.cs
//
// KEY DIFFERENCES:
//   C#:     namespace, using, file-scoped namespace, global using
//   Python: import module, from x import y, as alias
//   TS/JS:  import/export, ES modules vs CommonJS
//   Rust:   mod, pub, use, crate
//   Java:   package, import
//
// NOTE: dotnet script disallows inline `namespace` (CS7021).
//       Nested static types below mirror block namespaces; in a .csproj:
//         namespace MyApp.Constants { public static class Pi { ... } }
//         namespace MyApp.Greetings;  // file-scoped (C# 10+)
//         global using System;        // GlobalUsings.cs in SDK projects
// ============================================================

using System;
using Greeter = MyApp.Greetings.Greeter;           // type alias| Python: from myapp.greetings import Greeter
using Pow = System.Math;                           // alias     | Python: import math as pow

// ----- block namespace equivalents (nested static types for dotnet script) -----
static class MyApp
{
    public static class Constants
    {
        public static class Pi
        {
            public static double Value => 3.14;    // constant  | demo value (not Math.PI)
        }
    }

    public static class Greetings
    {
        public static class Greeter
        {
            public static string Greet() => "Hi";  // greet     | callable from main via using
        }
    }
}

// ----- top-level main — uses Math, namespaces, and alias -----
Console.WriteLine($"pi: {MyApp.Constants.Pi.Value:F2}");  // pi: 3.14 | MyApp.Constants
Console.WriteLine($"greet: {Greeter.Greet()}");           // greet: Hi | using Greeter = MyApp.Greetings.Greeter
Console.WriteLine($"sqrt: {Math.Sqrt(25):F1}");           // sqrt: 5.0 | System.Math
Console.WriteLine($"alias: {Pow.Pow(5, 2)}");             // alias: 25 | Pow aliases System.Math
Console.WriteLine("main module");                         // main module | entry-point output

// Cross-language note:
//   file-scoped namespace (C# 10+): `namespace MyApp;` — entire file in one namespace.
//   global using in GlobalUsings.cs — project-wide imports (SDK-style projects).
//   using static System.Math — import static members (Sqrt, PI) without type prefix.
//   Namespaces are logical grouping only — unlike Rust/Java packages, not physical modules by default.