// ============================================================
// Topic:  Inheritance
// Summary: A subclass reuses a base class, overrides methods, calls super.
// Run:     java java/12_inheritance.java   (Java 11+ single-file launch)
// ============================================================

public class Inheritance {
    public static void main(String[] args) {
        System.out.println(new Animal("Creature").describe());     // Creature says some sound
        System.out.println(new Dog("Rex", "Labrador").describe()); // Rex says Woof (Labrador)
        System.out.println(new Cat("Whiskers").describe());        // Whiskers says Meow
    }
}

class Animal {
    protected String name;
    Animal(String name) { this.name = name; }

    // methods are virtual by default in Java
    String sound() { return "some sound"; }
    String describe() { return name + " says " + sound(); }
}

// ----- 1. `extends` inherits; `super(name)` calls the base ctor -----
class Dog extends Animal {
    private String breed;
    Dog(String name, String breed) {
        super(name);
        this.breed = breed;
    }

    @Override String sound() { return "Woof"; }
    @Override String describe() { return super.describe() + " (" + breed + ")"; }
}

// ----- 2. Subclass that only overrides one method -----
class Cat extends Animal {
    Cat(String name) { super(name); }
    @Override String sound() { return "Meow"; }
}

// Cross-language note:
//   Java: `extends` for single inheritance; methods are virtual by default, so
//   describe() (on Animal) calls sound() and reaches the override. `super(...)` chains
//   the constructor, `super.m()` calls the parent. @Override is a checked annotation.
