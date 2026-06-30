// ============================================================
// Topic:  Abstraction
// Summary: An abstract base defines a contract; it can't be instantiated.
// Run:     java java/14_abstraction.java   (Java 11+ single-file launch)
// ============================================================

import java.util.Locale;

public class Abstraction {
    public static void main(String[] args) {
        System.out.println(new Circle(2).describe()); // Circle with radius 2 has area 12.57
        System.out.println(new Square(3).describe()); // Square with side 3 has area 9.00
        // new Shape(); // error: Shape is abstract; cannot be instantiated
    }
}

// ----- 1. Abstract class: declares WHAT, not HOW -----
abstract class Shape {
    abstract double area();   // no body = subclasses must implement
    abstract String label();

    // concrete method built on the abstract ones
    String describe() {
        return String.format(Locale.US, "%s has area %.2f", label(), area());
    }
}

// ----- 2. Concrete subclasses MUST implement every abstract method -----
class Circle extends Shape {
    private int r;
    Circle(int r) { this.r = r; }
    @Override double area() { return Math.PI * r * r; }
    @Override String label() { return "Circle with radius " + r; }
}

class Square extends Shape {
    private int s;
    Square(int s) { this.s = s; }
    @Override double area() { return s * s; }
    @Override String label() { return "Square with side " + s; }
}

// Cross-language note:
//   Java has `abstract class` (shown — mixes abstract + concrete members and state)
//   and `interface` (a pure contract; since Java 8 it may also carry `default` methods).
//   A concrete subclass that skips an abstract method won't compile.
