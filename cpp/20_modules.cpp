// ============================================================
// Topic:  Modules & Namespaces  (FOCUS: #include, namespace, using, alias)
// Summary: Header includes + namespace util — C++20 modules optional; headers universal.
// Run:     g++ -std=c++17 cpp/20_modules.cpp -o cpp/20_modules && cpp/20_modules
//
// KEY DIFFERENCES:
//   C++:     #include headers, namespace {}, using, namespace alias (C++17 has no modules by default)
//   Python:  import module, from x import y, as alias
//   Java:    import pkg.Class, packages as namespaces
//   C#:      using Namespace; using Alias = Full.Type;
//   Rust:    mod / use / pub mod, crate hierarchy
//   TS/JS:   import / export (ES modules)
// ============================================================

#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>

// ----- util namespace — groups related free functions and constants -----
namespace util {

constexpr double kPi = 3.141592653589793;

std::string greet(const std::string& name) { return "Hi, " + name; }

double square(double value) { return value * value; }

}  // namespace util

// ----- using declaration — bring single name into scope -----
using util::greet;

// ----- namespace alias — shorthand for qualified names -----
namespace u = util;

int main() {
    // ----- 1. util::kPi via namespace -----
    std::cout << "pi: " << std::fixed << std::setprecision(2) << util::kPi << std::endl;
    // Output: pi: 3.14

    // ----- 2. greet via using declaration (no util:: prefix) -----
    std::cout << "greet: " << greet("World").substr(0, 2) << std::endl;
    // Output: greet: Hi

    // ----- 3. <cmath> — std::sqrt from included header -----
    std::cout << "sqrt: " << std::fixed << std::setprecision(1) << std::sqrt(25.0) << std::endl;
    // Output: sqrt: 5.0

    // ----- 4. namespace alias u::square -----
    std::cout << "alias: " << static_cast<int>(u::square(5.0)) << std::endl;
    // Output: alias: 25

    std::cout << "main module" << std::endl;
    // Output: main module

    return 0;
}