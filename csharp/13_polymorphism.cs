// ============================================================
// Topic:  Polymorphism
// Summary: Treat different types through one base type; the right method runs.
// Run:     dotnet script csharp/13_polymorphism.cs
// ============================================================

using System;
using System.Collections.Generic;
using System.Globalization;

var shapes = new List<Shape> { new Circle(2), new Rectangle(3, 4) };
double total = 0;
foreach (var s in shapes)
{
    Console.WriteLine($"{s.Name()} area: {s.Area().ToString("F2", CultureInfo.InvariantCulture)}");
    total += s.Area();
}
Console.WriteLine($"Total area: {total.ToString("F2", CultureInfo.InvariantCulture)}");
// Output:
// Circle area: 12.57
// Rectangle area: 12.00
// Total area: 24.57

class Shape
{
    public virtual string Name() => "Shape";
    public virtual double Area() => 0.0;
}

class Circle : Shape
{
    private double r;
    public Circle(double r) { this.r = r; }
    public override string Name() => "Circle";
    public override double Area() => Math.PI * r * r;
}

class Rectangle : Shape
{
    private double w, h;
    public Rectangle(double w, double h) { this.w = w; this.h = h; }
    public override string Name() => "Rectangle";
    public override double Area() => w * h;
}

// Cross-language note:
//   A List<Shape> holds different subclasses; the virtual Area() dispatches to each
//   real type at runtime. (ToString("F2", InvariantCulture) keeps a '.' decimal point
//   regardless of the machine's locale.)
