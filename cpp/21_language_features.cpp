// ============================================================
// Topic:  Language Features  (FOCUS: RAII, move, range-for, auto, constexpr, &)
// Summary: Six C++-specific idioms — smart pointers, move semantics, modern syntax.
// Run:     g++ -std=c++17 cpp/21_language_features.cpp -o cpp/21_language_features && cpp/21_language_features
//
// KEY DIFFERENCES:
//   C++:     unique_ptr/RAII, std::move, range-for, auto, constexpr, lvalue &
//   Python:  with/context managers, no move, for x in, hints optional, no constexpr
//   Java:    try-with-resources, no move, enhanced for, var (10+), final static
//   C#:      using/dispose, no move, foreach, var, const, ref/out params
//   Rust:    Drop/ownership, move by default, for x in, inference, const, &
//   TS:      no RAII, no move, for-of, inference, const, no true references
// ============================================================

#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <vector>

// ----- RAII helper — destructor runs when unique_ptr leaves scope -----
class Resource {
public:
    ~Resource() {}
};

int main() {
    // ----- 1. RAII with std::unique_ptr — automatic cleanup at scope end -----
    {
        std::unique_ptr<Resource> resource = std::make_unique<Resource>();
    }
    std::cout << "raii: done" << std::endl;
    // Output: raii: done

    // ----- 2. std::move — transfer string buffer without copying -----
    std::string source = "moved";
    std::string destination = std::move(source);
    std::cout << "move: " << destination << std::endl;
    // Output: move: moved

    // ----- 3. Range-based for — iterate container elements -----
    std::vector<int> values = {1, 2, 3};
    std::cout << "range:";
    for (int value : values) {
        std::cout << " " << value;
    }
    std::cout << std::endl;
    // Output: range: 1 2 3

    // ----- 4. auto — compiler deduces type from initializer -----
    auto answer = 42;
    std::cout << "auto: " << answer << std::endl;
    // Output: auto: 42

    // ----- 5. constexpr — compile-time constant expression -----
    constexpr int doubled = 5 * 2;
    std::cout << "constexpr: " << doubled << std::endl;
    // Output: constexpr: 10

    // ----- 6. Reference (&) — alias modifies the original variable -----
    int number = 0;
    int& alias = number;
    alias = 99;
    std::cout << "ref: " << number << std::endl;
    // Output: ref: 99

    return 0;
}