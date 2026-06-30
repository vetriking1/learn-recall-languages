// ============================================================
// Topic:  Conditions
// Summary: if / else if / else, ternary, switch, explicit bool.
// Run:     g++ -std=c++17 cpp/04_conditions.cpp -o cpp/04_conditions && cpp/04_conditions
// ============================================================

#include <iostream>
#include <string>

int main() {
    // ----- 1. Basic if / else if / else -----
    int age = 20;
    if (age < 13) {
        std::cout << "child" << std::endl;
    } else if (age < 18) {
        std::cout << "teen" << std::endl;
    } else {
        std::cout << "adult" << std::endl;
    }
    // Output: adult

    // ----- 2. Ternary (conditional expression) -----
    std::string status = (age >= 18) ? "pass" : "fail";
    std::cout << status << std::endl;
    // Output: pass
    // Python: "pass" if age >= 18 else "fail"
    // TS:     age >= 18 ? "pass" : "fail"

    // ----- 3. No implicit bool for non-bool types -----
    int count = 5;
    std::string name = "hello";
    // if (count) { }       // compiles but discouraged — use explicit comparison
    // if (name) { }        // ERROR in modern C++: no conversion from string to bool
    if (count > 0) {
        std::cout << "count is positive" << std::endl;
    }
    // Output: count is positive
    if (!name.empty()) {
        std::cout << "non-empty string" << std::endl;
    }
    // Output: non-empty string
    // Python truthiness: 0, "", [] are falsy. C++ requires explicit bool expressions.

    // ----- 4. Combining conditions -----
    int temp = 25;
    if (temp > 20 && temp < 30) {
        std::cout << "comfortable" << std::endl;
    }
    // Output: comfortable

    // ----- 5. switch / case (fall-through without break!) -----
    char cmd = 's';  // maps to command "start"
    switch (cmd) {
        case 's':
            std::cout << "starting" << std::endl;
            break;  // required — otherwise execution falls through to next case
        case 'x':
            std::cout << "stopping" << std::endl;
            break;
        default:
            std::cout << "unknown" << std::endl;
    }
    // Output: starting
    // switch works on integral/enum types only — not std::string (use if/else chain).

    // ----- 6. switch on int (common pattern) -----
    int grade = 2;
    switch (grade) {
        case 1: std::cout << "A"; break;
        case 2: std::cout << "B"; break;
        case 3: std::cout << "C"; break;
        default: std::cout << "?";
    }
    std::cout << std::endl;
    // Output: B

    // Cross-language note:
    //   C++:     if (x > 0) { }   switch (n) { case 1: ... break; }
    //   Python:  if x > 0:        match command: case "start": ...
    //   TS:      if (x > 0) { }   switch (n) { case 1: ... break; }
    //   Rust:    if x > 0 { }     match command { "start" => ..., _ => ... }
    //   C#:      if (x > 0) { }   switch (n) { case 1: ... break; }
    //   C++ switch needs break; Python match/TS switch don't fall through by default.
    return 0;
}