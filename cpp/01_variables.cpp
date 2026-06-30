// ============================================================
// Topic:  Variables
// Summary: Declaration, types, const, constexpr, naming, swap.
// Run:     g++ -std=c++17 cpp/01_variables.cpp -o cpp/01_variables && cpp/01_variables
// ============================================================

#include <iostream>
#include <string>
#include <utility>  // std::swap

int main() {
    // ----- 1. Basic declaration (explicit types) -----
    std::string name = "Vetri";
    int age = 22;
    double price = 99.5;
    std::cout << name << " " << age << " " << price << std::endl;
    // Output: Vetri 22 99.5

    // ----- 2. auto — type inference (like TS let / Rust let / C# var) -----
    auto score = 10;           // inferred as int
    auto label = "hello";      // inferred as const char*
    auto ratio = 3.14;         // inferred as double
    std::cout << score << " " << label << " " << ratio << std::endl;
    // Output: 10 hello 3.14

    // ----- 3. const — runtime constant (cannot reassign) -----
    const int MAX_USERS = 100;
    std::cout << MAX_USERS << std::endl;
    // Output: 100
    // MAX_USERS = 200;  // ERROR: assignment of read-only variable

    // ----- 4. constexpr — compile-time constant -----
    constexpr double PI = 3.14159;
    std::cout << PI << std::endl;
    // Output: 3.14159

    // ----- 5. Reassigning mutable variables -----
    score = 20;
    std::cout << score << std::endl;
    // Output: 20

    // ----- 6. Multiple assignment -----
    int x = 1, y = 2, z = 3;
    int a = 0, b = 0, c = 0;  // all start at 0
    std::cout << x << " " << y << " " << z << " " << a << " " << b << " " << c << std::endl;
    // Output: 1 2 3 0 0 0

    // ----- 7. Swapping (std::swap — no tuple destructure like Python) -----
    std::swap(x, y);
    std::cout << x << " " << y << std::endl;
    // Output: 2 1

    // ----- 8. Naming: snake_case convention -----
    double total_price = 99.5;  // good   (TS/C# use camelCase: totalPrice)
    std::cout << total_price << std::endl;
    // Output: 99.5

    // ----- 9. Static typing (no silent type change on rebind) -----
    int thing = 5;
    // thing = "text";  // ERROR: cannot convert const char* to int
    std::cout << thing << std::endl;
    // Output: 5

    // Cross-language note:
    //   C++:     int age = 22;  const int MAX = 100;  constexpr double PI = 3.14;
    //   Rust:    let age = 22;  const PI: f64 = 3.14;  (let is immutable unless mut)
    //   TS:      let age = 22;  const MAX = 100;
    //   Python:  age = 22       (no keyword, no real const)
    //   C#:      int age = 22;  const int MAX = 100;
    //   C++ has both const (runtime) and constexpr (compile-time); use std::swap for swap.
    return 0;
}