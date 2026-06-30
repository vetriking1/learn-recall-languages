// ============================================================
// Topic:  Abstraction
// Summary: An abstract base defines a contract; it can't be instantiated.
// Run:     dotnet script csharp/14_abstraction.cs
// ============================================================

using System;
using System.Globalization;

Console.WriteLine(new Circle(2).Describe()); // Output: Circle with radius 2 has area 12.57
Console.WriteLine(new Square(3).Describe()); // Output: Square with side 3 has area 9.00
// new Shape(); // error: Cannot create an instance of the abstract type 'Shape'

// ----- 1. Abstract class: declares WHAT, not HOW -----
abstract class Shape
{
    public abstract double Area();   // no body = subclasses must implement
    public abstract string Label();

    // concrete method built on the abstract ones
    public string Describe() =>
        $"{Label()} has area {Area().ToString("F2", CultureInfo.InvariantCulture)}";
}

// ----- 2. Concrete subclasses MUST implement every abstract member -----
class Circle : Shape
{
    private int r;
    public Circle(int r) { this.r = r; }
    public override double Area() => Math.PI * r * r;
    public override string Label() => $"Circle with radius {r}";
}

class Square : Shape
{
    private int s;
    public Square(int s) { this.s = s; }
    public override double Area() => s * s;
    public override string Label() => $"Square with side {s}";
}

// Cross-language note:
//   C# has `abstract class` (shown — may mix abstract + concrete members and state)
//   and `interface` (pure contract). `abstract`/`override` are compiler-enforced: a
//   concrete subclass that skips an abstract member won't compile.
