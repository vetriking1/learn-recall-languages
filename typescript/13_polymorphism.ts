// ============================================================
// Topic:  Polymorphism
// Summary: Treat different types through one interface; the right method runs.
// Run:     cd typescript && npx ts-node 13_polymorphism.ts
// ============================================================

class Shape {
  name(): string {
    return "Shape";
  }
  area(): number {
    return 0;
  }
}

class Circle extends Shape {
  constructor(private r: number) {
    super();
  }
  name(): string {
    return "Circle";
  }
  area(): number {
    return Math.PI * this.r ** 2;
  }
}

class Rectangle extends Shape {
  constructor(private w: number, private h: number) {
    super();
  }
  name(): string {
    return "Rectangle";
  }
  area(): number {
    return this.w * this.h;
  }
}

// ----- One loop over a Shape[]; each call dispatches to the real subclass -----
const shapes: Shape[] = [new Circle(2), new Rectangle(3, 4)];
let total = 0;
for (const s of shapes) {
  console.log(`${s.name()} area: ${s.area().toFixed(2)}`);
  total += s.area();
}
console.log(`Total area: ${total.toFixed(2)}`);
// Output:
// Circle area: 12.57
// Rectangle area: 12.00
// Total area: 24.57

// Cross-language note:
//   The variable is typed as the base `Shape`, but s.area() runs the subclass version.
//   TS also has structural typing: anything with the same shape is assignable, no
//   explicit `extends` required.
