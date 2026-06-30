// ============================================================
// Topic:  Error Handling  (FOCUS: try/catch, throw, std::exception, RAII finally)
// Summary: Exceptions with std::exception hierarchy — scope guard simulates finally.
// Run:     g++ -std=c++17 cpp/18_error_handling.cpp -o cpp/18_error_handling && cpp/18_error_handling
//
// KEY DIFFERENCES:
//   C++:     try/catch/throw, std::exception, RAII for cleanup (no finally keyword)
//   Python:  try/except/finally, raise, custom Exception subclasses
//   Java:    try/catch/finally, throw, checked vs unchecked exceptions
//   C#:      try/catch/finally, throw, Exception base class
//   Rust:    Result<T,E> / ? operator — no exceptions by default
//   TS/JS:   try/catch/finally, throw, Error objects
// ============================================================

#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>

// ----- Custom exception — inherits std::exception (what() contract) -----
class CustomBad : public std::exception {
    std::string message_;

public:
    explicit CustomBad(std::string message) : message_(std::move(message)) {}

    const char* what() const noexcept override { return message_.c_str(); }
};

// ----- RAII scope guard — destructor runs on scope exit ("finally") -----
class FinallyGuard {
public:
    FinallyGuard() = default;
    ~FinallyGuard() { std::cout << "finally ran" << std::endl; }

    FinallyGuard(const FinallyGuard&) = delete;
    FinallyGuard& operator=(const FinallyGuard&) = delete;
};

int safe_divide(int numerator, int denominator) {
    if (denominator == 0) {
        throw std::runtime_error("division by zero");
    }
    return numerator / denominator;
}

int main() {
    // ----- 1. Successful path — no exception thrown -----
    try {
        std::cout << "result: " << safe_divide(20, 2) << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "unexpected: " << e.what() << std::endl;
    }
    // Output: result: 10

    // ----- 2. catch std::exception — store message from what() -----
    try {
        safe_divide(10, 0);
    } catch (const std::exception& e) {
        std::cout << "caught: " << e.what() << std::endl;
    }
    // Output: caught: division by zero

    // ----- 3. Custom exception + finally guard + rethrow to outer catch -----
    try {
        try {
            throw CustomBad("invalid");
        } catch (const CustomBad& e) {
            std::cout << "CustomBad: " << e.what() << std::endl;
            {
                FinallyGuard guard;  // RAII — prints on scope exit
            }
            throw std::runtime_error("inner failed");
        }
    } catch (const std::exception& e) {
        std::cout << "outer: " << e.what() << std::endl;
    }
    // Output: CustomBad: invalid
    // Output: finally ran
    // Output: outer: inner failed

    return 0;
}