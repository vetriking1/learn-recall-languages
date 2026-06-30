// ============================================================
// Topic:  Classes & Objects
// Summary: Define a class (state + behavior), construct instances, call methods.
// Run:     dotnet script csharp/10_classes.cs
// ============================================================

using System;

// ----- 4. Create objects (instances) with `new` and call methods -----
// (Top-level statements run first; the class is declared below.)
var p1 = new Person("Vetri", 22);
var p2 = new Person("Asha", 30);
Console.WriteLine(p1.Greet()); // Output: Hi, I'm Vetri and I'm 22
Console.WriteLine(p2.Greet()); // Output: Hi, I'm Asha and I'm 30

p1.Birthday();                 // mutate p1's state
Console.WriteLine(p1.Greet()); // Output: Hi, I'm Vetri and I'm 23

// ----- 1. Define a class with a constructor and methods -----
class Person
{
    // fields (private backing state)
    private string name;
    private int age;

    // ----- constructor -----
    public Person(string name, int age)
    {
        this.name = name;
        this.age = age;
    }

    // ----- 2. Instance method -----
    public string Greet() => $"Hi, I'm {name} and I'm {age}";

    // ----- 3. Method that mutates instance state -----
    public void Birthday() => age += 1;
}

// Cross-language note:
//   C#: constructor is a method named like the class; instance is `this`.
//   Methods/types are PascalCase by convention. Use `new` to construct.
//   Fields default to private; expose via methods or properties (see 11_encapsulation).
