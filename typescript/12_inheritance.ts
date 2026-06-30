// ============================================================
// Topic:  Inheritance
// Summary: A subclass reuses a base class, overrides methods, calls super.
// Run:     cd typescript && npx ts-node 12_inheritance.ts
// ============================================================

class Animal {
  constructor(public name: string) {}

  sound(): string {
    return "some sound";
  }

  describe(): string {
    return `${this.name} says ${this.sound()}`;
  }
}

// ----- 1. extends + super() to reuse the base -----
class Dog extends Animal {
  constructor(name: string, public breed: string) {
    super(name); // run Animal's constructor
  }

  sound(): string {
    return "Woof"; // override
  }

  describe(): string {
    return `${super.describe()} (${this.breed})`; // extend base behavior
  }
}

// ----- 2. Subclass that only overrides one method -----
class Cat extends Animal {
  sound(): string {
    return "Meow";
  }
}

console.log(new Animal("Creature").describe());     // Output: Creature says some sound
console.log(new Dog("Rex", "Labrador").describe()); // Output: Rex says Woof (Labrador)
console.log(new Cat("Whiskers").describe());        // Output: Whiskers says Meow

// Cross-language note:
//   TS: `class Dog extends Animal`; `super(...)` calls the base ctor, `super.m()` the base method.
//   Methods are virtual by default — describe() (on Animal) calls this.sound() and
//   dispatches to the subclass override. TS has single inheritance (one base class).
