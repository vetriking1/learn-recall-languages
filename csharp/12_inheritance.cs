// ============================================================
// Topic:  Inheritance
// Summary: A subclass reuses a base class, overrides virtual methods, calls base.
// Run:     dotnet script csharp/12_inheritance.cs
// ============================================================

using System;

Console.WriteLine(new Animal("Creature").Describe());     // Output: Creature says some sound
Console.WriteLine(new Dog("Rex", "Labrador").Describe()); // Output: Rex says Woof (Labrador)
Console.WriteLine(new Cat("Whiskers").Describe());        // Output: Whiskers says Meow

class Animal
{
    protected string Name;
    public Animal(string name) { Name = name; }

    // `virtual` allows subclasses to override
    public virtual string Sound() => "some sound";
    public virtual string Describe() => $"{Name} says {Sound()}";
}

// ----- 1. `: Animal` inherits; `: base(name)` calls the base ctor -----
class Dog : Animal
{
    private string breed;
    public Dog(string name, string breed) : base(name) { this.breed = breed; }

    public override string Sound() => "Woof";
    public override string Describe() => $"{base.Describe()} ({breed})";
}

// ----- 2. Subclass that only overrides one method -----
class Cat : Animal
{
    public Cat(string name) : base(name) { }
    public override string Sound() => "Meow";
}

// Cross-language note:
//   C#: opt-in overriding — base methods must be `virtual`, subclasses say `override`.
//   `: Base` inherits; `: base(...)` chains the constructor; `base.M()` calls the parent.
//   (A non-virtual method hidden with `new` would NOT dispatch polymorphically.)
