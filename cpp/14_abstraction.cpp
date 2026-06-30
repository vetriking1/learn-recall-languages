// ============================================================
// Topic:  Abstraction
// Summary: A pure-virtual method makes a class abstract (cannot instantiate).
// Run:     g++ -std=c++17 cpp/14_abstraction.cpp -o cpp/14_abstraction && cpp/14_abstraction
// ============================================================

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

const double PI = 3.141592653589793;

// ----- 1. Abstract class: a "= 0" pure virtual declares WHAT, not HOW -----
class Shape {
public:
    virtual ~Shape() = default;
    virtual double area() const = 0;        // pure virtual -> Shape is abstract
    virtual std::string label() const = 0;

    // concrete method built on the abstract ones
    std::string describe() const {
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(2);
        oss << label() << " has area " << area();
        return oss.str();
    }
};

// ----- 2. Concrete subclasses MUST override every pure virtual -----
class Circle : public Shape {
    int r;
public:
    Circle(int r) : r(r) {}
    double area() const override { return PI * r * r; }
    std::string label() const override { return "Circle with radius " + std::to_string(r); }
};

class Square : public Shape {
    int s;
public:
    Square(int s) : s(s) {}
    double area() const override { return static_cast<double>(s * s); }
    std::string label() const override { return "Square with side " + std::to_string(s); }
};

int main() {
    // Shape s; // error: cannot declare variable 's' to be of abstract type 'Shape'
    std::cout << Circle(2).describe() << std::endl; // Circle with radius 2 has area 12.57
    std::cout << Square(3).describe() << std::endl; // Square with side 3 has area 9.00
    return 0;
}

// Cross-language note:
//   C++ has no `abstract` keyword — a class becomes abstract simply by having a
//   pure virtual method (`= 0`). Such a class can't be instantiated; a subclass that
//   leaves any pure virtual unimplemented stays abstract too.
