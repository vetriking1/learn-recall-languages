// ============================================================
// Topic:  Operators
// Summary: Arithmetic, comparison, logical, ternary, no coercion.
// Run:     g++ -std=c++17 cpp/03_operators.cpp -o cpp/03_operators && cpp/03_operators
// ============================================================

#include <iostream>
#include <cmath>
#include <string>

int main() {
    // ----- 1. Arithmetic -----
    std::cout << 5 + 2 << std::endl;   // Output: 7
    std::cout << 5 - 2 << std::endl;   // Output: 3
    std::cout << 5 * 2 << std::endl;   // Output: 10
    std::cout << 5 / 2 << std::endl;   // Output: 2  (integer division when both operands are int)
    std::cout << 5.0 / 2 << std::endl; // Output: 2.5
    std::cout << 5 % 2 << std::endl;   // Output: 1
    std::cout << static_cast<int>(std::pow(5, 2)) << std::endl;
    // Output: 25   (no ** operator; use std::pow — Python: 5**2, TS: 5**2)

    // ----- 2. Comparison (return bool) -----
    std::cout << std::boolalpha;
    std::cout << (5 == 5) << std::endl;   // Output: true
    std::cout << (5 != 3) << std::endl;   // Output: true
    std::cout << (5 > 3) << " " << (5 < 3) << " "
              << (5 >= 5) << " " << (5 <= 4) << std::endl;
    // Output: true false true false

    // ----- 3. Logical (symbols, like TS/C/Java — not Python's and/or/not) -----
    std::cout << (true && false) << std::endl;  // Output: false
    std::cout << (true || false) << std::endl;  // Output: true
    std::cout << (!true) << std::endl;          // Output: false

    // ----- 4. No implicit coercion between unrelated types -----
    int n = 5;
    std::string text = "5";
    // std::cout << (n == text);  // ERROR: no == between int and string
    std::cout << (n == std::stoi(text)) << std::endl;
    // Output: true   (must convert explicitly — TS/Python may coerce in loose comparisons)

    // ----- 5. Ternary (conditional expression) -----
    int age = 20;
    std::string status = (age >= 18) ? "pass" : "fail";
    std::cout << status << std::endl;
    // Output: pass
    // Python order: "pass" if age >= 18 else "fail"

    // ----- 6. Augmented assignment -----
    n = 10;
    n += 5;  std::cout << n << std::endl;  // Output: 15
    n -= 3;  std::cout << n << std::endl;  // Output: 12
    n *= 2;  std::cout << n << std::endl;  // Output: 24
    n /= 5;  std::cout << n << std::endl;  // Output: 4
    // C++ has ++ and -- (Python does not): n++; n--;

    // ----- 7. Chained comparison (NOT supported — unlike Python) -----
    int x = 5;
    std::cout << (1 < x && x < 10) << std::endl;
    // Output: true   (Python: 1 < x < 10)

    // Cross-language note:
    //   Power:  C++ std::pow(5,2)  |  Python 5**2  |  TS 5**2
    //   Logic:  C++ && || !        |  Python and or not  |  TS && || !
    //   Equality: C++ == is typed; no loose == like JS. Compare after explicit cast.
    //   Increment: C++ has ++/--; Python uses n += 1.
    return 0;
}