// ============================================================
// Topic:  Inheritance
// Summary: A subclass reuses a base class, overrides virtual methods, calls base.
// Run:     g++ -std=c++17 cpp/12_inheritance.cpp -o cpp/12_inheritance && cpp/12_inheritance
// ============================================================

#include <iostream>
#include <string>

class Animal {
protected:
    std::string name;

public:
    Animal(const std::string& name) : name(name) {}
    virtual ~Animal() = default;                 // virtual dtor for safe polymorphism

    // `virtual` enables runtime dispatch to overrides
    virtual std::string sound() const { return "some sound"; }
    virtual std::string describe() const { return name + " says " + sound(); }
};

// ----- 1. `: public Animal` inherits; `Animal(name)` calls the base ctor -----
class Dog : public Animal {
    std::string breed;

public:
    Dog(const std::string& name, const std::string& breed)
        : Animal(name), breed(breed) {}

    std::string sound() const override { return "Woof"; }
    std::string describe() const override { return Animal::describe() + " (" + breed + ")"; }
};

// ----- 2. Subclass that only overrides one method -----
class Cat : public Animal {
public:
    Cat(const std::string& name) : Animal(name) {}
    std::string sound() const override { return "Meow"; }
};

int main() {
    std::cout << Animal("Creature").describe() << std::endl;     // Creature says some sound
    std::cout << Dog("Rex", "Labrador").describe() << std::endl; // Rex says Woof (Labrador)
    std::cout << Cat("Whiskers").describe() << std::endl;        // Whiskers says Meow
    return 0;
}

// Cross-language note:
//   C++: methods must be `virtual` to dispatch dynamically; subclasses add `override`.
//   `: public Animal` inherits; `Animal(name)` in the init list chains the base ctor;
//   `Animal::describe()` calls the parent version. Always give a polymorphic base a virtual dtor.
