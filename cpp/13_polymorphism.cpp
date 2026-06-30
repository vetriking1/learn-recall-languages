// ============================================================
// Topic:  Polymorphism
// Summary: Treat different types through a base pointer; the right method runs.
// Run:     g++ -std=c++17 cpp/13_polymorphism.cpp -o cpp/13_polymorphism && cpp/13_polymorphism
// ============================================================

#include <iostream>
#include <iomanip>
#include <vector>
#include <memory>
#include <string>

const double PI = 3.141592653589793;

class Shape {
public:
    virtual ~Shape() = default;
    virtual std::string name() const { return "Shape"; }
    virtual double area() const { return 0.0; }
};

class Circle : public Shape {
    double r;
public:
    Circle(double r) : r(r) {}
    std::string name() const override { return "Circle"; }
    double area() const override { return PI * r * r; }
};

class Rectangle : public Shape {
    double w, h;
public:
    Rectangle(double w, double h) : w(w), h(h) {}
    std::string name() const override { return "Rectangle"; }
    double area() const override { return w * h; }
};

int main() {
    // Polymorphism needs a pointer or reference to the base type.
    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.push_back(std::make_unique<Circle>(2));
    shapes.push_back(std::make_unique<Rectangle>(3, 4));

    double total = 0;
    std::cout << std::fixed << std::setprecision(2);
    for (const auto& s : shapes) {
        std::cout << s->name() << " area: " << s->area() << std::endl;
        total += s->area();
    }
    std::cout << "Total area: " << total << std::endl;
    // Output:
    // Circle area: 12.57
    // Rectangle area: 12.00
    // Total area: 24.57
    return 0;
}

// Cross-language note:
//   Dynamic dispatch in C++ happens only through a base POINTER or REFERENCE to a
//   `virtual` method. Storing objects by value (a std::vector<Shape>) would "slice"
//   them down to the base, so we hold unique_ptr<Shape> instead.
