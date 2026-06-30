// ============================================================
// Topic:  Data Types
// Summary: Core scalar types, nullptr, typeid, casting, stringstream.
// Run:     g++ -std=c++17 cpp/02_datatypes.cpp -o cpp/02_datatypes && cpp/02_datatypes
// ============================================================

#include <iostream>
#include <string>
#include <sstream>
#include <typeinfo>

int main() {
    // ----- 1. The core scalar types -----
    int an_int = 42;
    double a_float = 3.14;
    std::string a_str = "hello";
    bool a_bool = true;
    char a_char = 'A';
    int* nothing = nullptr;  // C++ null pointer   (Python: None, TS: null)
    std::cout << an_int << " " << a_float << " " << a_str << " "
              << std::boolalpha << a_bool << " " << a_char << " "
              << (nothing == nullptr ? "nullptr" : "ptr") << std::endl;
    // Output: 42 3.14 hello true A nullptr

    // ----- 2. Checking a type (typeid) -----
    std::cout << typeid(an_int).name() << std::endl;
    // Output: i  (implementation-defined; often mangled like "int" on MSVC)
    std::cout << typeid(a_str).name() << std::endl;
    // Output: NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE  (or similar)

    // ----- 3. static_cast — explicit conversion (no implicit coercion) -----
    double pi = 3.99;
    int truncated = static_cast<int>(pi);
    std::cout << truncated << std::endl;
    // Output: 3

    std::string num_text = "10";
    int parsed = std::stoi(num_text);
    std::cout << parsed + 5 << std::endl;
    // Output: 15

    std::cout << std::to_string(10) + "5" << std::endl;
    // Output: 105

    // ----- 4. stringstream — build/parse strings -----
    std::ostringstream oss;
    oss << "value=" << 42;
    std::cout << oss.str() << std::endl;
    // Output: value=42

    std::istringstream iss("3.5");
    double from_stream;
    iss >> from_stream;
    std::cout << from_stream << std::endl;
    // Output: 3.5

    // ----- 5. Numeric detail -----
    std::cout << 7 / 2 << std::endl;       // integer division   Output: 3
    std::cout << 7.0 / 2 << std::endl;     // float division      Output: 3.5
    std::cout << 10 % 3 << std::endl;      // modulo              Output: 1

    // ----- 6. bool converts only from bool expressions -----
    std::cout << std::boolalpha << (an_int != 0) << " "
              << (!a_str.empty()) << std::endl;
    // Output: true true
    // Note: unlike Python, non-zero int is NOT implicitly truthy in if() — compare explicitly.

    // Cross-language note:
    //   C++:  int / double / bool / char / std::string / nullptr
    //   Python: int / float / bool / str / None  (dynamic; type() at runtime)
    //   TS:   number / boolean / string / null / undefined
    //   Rust: i32 / f64 / bool / char / String / None (Option)
    //   C#:   int / double / bool / char / string / null
    //   C++ is statically typed; use static_cast or stoi/stod for conversions, not silent coercion.
    return 0;
}