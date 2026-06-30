// ============================================================
// Topic:  Abstraction
// Summary: An abstract base defines a contract; it can't be instantiated.
// Run:     cd typescript && npx ts-node 14_abstraction.ts
// ============================================================

// ----- 1. Abstract class: declares WHAT, not HOW -----
abstract class Shape {
  abstract area(): number; // no body = subclasses must implement
  abstract label(): string;

  // concrete method built on the abstract ones
  describe(): string {
    return `${this.label()} has area ${this.area().toFixed(2)}`;
  }
}

// ----- 2. Concrete subclasses MUST implement every abstract member -----
class Circle extends Shape {
  constructor(private r: number) {
    super();
  }
  area(): number {
    return Math.PI * this.r ** 2;
  }
  label(): string {
    return `Circle with radius ${this.r}`;
  }
}

class Square extends Shape {
  constructor(private s: number) {
    super();
  }
  area(): number {
    return this.s * this.s;
  }
  label(): string {
    return `Square with side ${this.s}`;
  }
}

// new Shape(); // error: Cannot create an instance of an abstract class
console.log(new Circle(2).describe()); // Output: Circle with radius 2 has area 12.57
console.log(new Square(3).describe()); // Output: Square with side 3 has area 9.00

// Cross-language note:
//   TS has both `abstract class` (shown here, can hold concrete code + state) and
//   `interface` (pure contract, no implementation, erased at runtime). Use an interface
//   when you only need the shape of a type; an abstract class when you also share code.
