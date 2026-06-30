// ============================================================
// Topic:  Classes & Objects
// Summary: Define a class (state + behavior), construct instances, call methods.
// Run:     g++ -std=c++17 cpp/10_classes.cpp -o cpp/10_classes && cpp/10_classes
// ============================================================

#include <iostream>
#include <string>

// ----- 1. Define a class with a constructor and methods -----
class Person {
private:
    std::string name; // members are private by default in a class
    int age;

public:
    // ----- constructor (member initializer list) -----
    Person(const std::string& name, int age) : name(name), age(age) {}

    // ----- 2. Instance method -----
    std::string greet() const {
        return "Hi, I'm " + name + " and I'm " + std::to_string(age);
    }

    // ----- 3. Method that mutates instance state -----
    void birthday() { age += 1; }
};

int main() {
    // ----- 4. Create objects and call methods -----
    Person p1("Vetri", 22);          // stack object (no `new` needed)
    Person p2("Asha", 30);
    std::cout << p1.greet() << std::endl; // Output: Hi, I'm Vetri and I'm 22
    std::cout << p2.greet() << std::endl; // Output: Hi, I'm Asha and I'm 30

    p1.birthday();                        // mutate p1's state
    std::cout << p1.greet() << std::endl; // Output: Hi, I'm Vetri and I'm 23
    return 0;
}

// Cross-language note:
//   C++: members are private by default in `class` (public by default in `struct`).
//   Constructor has the class's name; `this` is a pointer. `const` methods can't mutate.
//   Objects can live on the stack (Person p;) — no `new` / garbage collector required.
