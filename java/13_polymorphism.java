// ============================================================
// Topic:  Polymorphism
// Summary: Treat different types through one base type; the right method runs.
// Run:     java java/13_polymorphism.java   (Java 11+ single-file launch)
// ============================================================

import java.util.ArrayList;
import java.util.List;
import java.util.Locale;

public class Polymorphism {
    public static void main(String[] args) {
        List<Shape> shapes = new ArrayList<>();
        shapes.add(new Circle(2));
        shapes.add(new Rectangle(3, 4));

        double total = 0;
        for (Shape s : shapes) {
            System.out.printf(Locale.US, "%s area: %.2f%n", s.name(), s.area());
            total += s.area();
        }
        System.out.printf(Locale.US, "Total area: %.2f%n", total);
        // Output:
        // Circle area: 12.57
        // Rectangle area: 12.00
        // Total area: 24.57
    }
}

class Shape {
    String name() { return "Shape"; }
    double area() { return 0.0; }
}

class Circle extends Shape {
    private double r;
    Circle(double r) { this.r = r; }
    @Override String name() { return "Circle"; }
    @Override double area() { return Math.PI * r * r; }
}

class Rectangle extends Shape {
    private double w, h;
    Rectangle(double w, double h) { this.w = w; this.h = h; }
    @Override String name() { return "Rectangle"; }
    @Override double area() { return w * h; }
}

// Cross-language note:
//   A List<Shape> holds different subclasses; methods are virtual by default, so
//   s.area() runs the real type's version. (Locale.US keeps a '.' decimal separator
//   regardless of the machine's locale.)
