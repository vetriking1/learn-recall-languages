// ============================================================
// Topic:  Classes & Objects
// Summary: Define a class (state + behavior), construct instances, call methods.
// Run:     cd typescript && npx ts-node 10_classes.ts
// ============================================================

// ----- 1. Define a class with a constructor and methods -----
class Person {
  name: string; // field declarations (required under strict mode)
  age: number;

  // constructor runs on `new`
  constructor(name: string, age: number) {
    this.name = name;
    this.age = age;
  }

  // ----- 2. Instance method (uses this) -----
  greet(): string {
    return `Hi, I'm ${this.name} and I'm ${this.age}`;
  }

  // ----- 3. Method that mutates instance state -----
  birthday(): void {
    this.age += 1;
  }
}

// ----- 4. Create objects (instances) with `new` and call methods -----
const p1 = new Person("Vetri", 22);
const p2 = new Person("Asha", 30);
console.log(p1.greet()); // Output: Hi, I'm Vetri and I'm 22
console.log(p2.greet()); // Output: Hi, I'm Asha and I'm 30

p1.birthday();           // mutate p1's state
console.log(p1.greet()); // Output: Hi, I'm Vetri and I'm 23

// Cross-language note:
//   TS: `constructor` keyword; instance is `this`. Use `new` to construct.
//   Shorthand: constructor(public name: string) auto-creates+assigns the field.
//   Fields are public by default; see 11_encapsulation for private/#.
