// ============================================================
// Topic:  Functions
// Summary: Return types, defaults, overloading, initializer_list, pair.
// Run:     g++ -std=c++17 cpp/07_functions.cpp -o cpp/07_functions && cpp/07_functions
// ============================================================

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <initializer_list>
#include <algorithm>

// ----- 1. Basic function -----
std::string greet(const std::string& name) {
    return "Hello, " + name;
}

// ----- 2. Typed return -----
int add(int a, int b) {
    return a + b;
}

// ----- 3. void — no return value -----
void log_message(const std::string& msg) {
    std::cout << "[log] " << msg << std::endl;
}

// ----- 4. Default parameters -----
int power(int base, int exp = 2) {
    int result = 1;
    for (int i = 0; i < exp; ++i) result *= base;
    return result;
}

// ----- 5. Function overloading (same name, different signatures) -----
int multiply(int a, int b) {
    return a * b;
}

double multiply(double a, double b) {
    return a * b;
}

// ----- 6. Variadic via initializer_list (like Python *args) -----
int total(std::initializer_list<int> numbers) {
    int sum = 0;
    for (int n : numbers) sum += n;
    return sum;
}

// ----- 7. Returning multiple values via std::pair -----
std::pair<int, int> min_max(const std::vector<int>& nums) {
    auto bounds = std::minmax_element(nums.begin(), nums.end());
    return {*bounds.first, *bounds.second};
}

int main() {
    std::cout << greet("Vetri") << std::endl;
    // Output: Hello, Vetri

    std::cout << add(2, 3) << std::endl;
    // Output: 5

    log_message("started");
    // Output: [log] started

    std::cout << power(5) << std::endl;
    // Output: 25
    std::cout << power(5, 3) << std::endl;
    // Output: 125

    std::cout << multiply(3, 4) << std::endl;
    // Output: 12
    std::cout << multiply(2.5, 2.0) << std::endl;
    // Output: 5

    std::cout << total({1, 2, 3, 4}) << std::endl;
    // Output: 10

    auto min_max_vals = min_max({4, 1, 9, 2});
    std::cout << min_max_vals.first << " " << min_max_vals.second << std::endl;
    // Output: 1 9

    // ----- 8. Lambda (anonymous function — like Python lambda / TS arrow) -----
    auto square = [](int x) { return x * x; };
    std::cout << square(6) << std::endl;
    // Output: 36

    // Cross-language note:
    //   C++:     int add(int a, int b) { return a+b; }   overloads + default args
    //   Python:  def add(a, b): ...                       *args/**kwargs
    //   TS:      function add(a: number, b: number)      ...rest params
    //   Rust:    fn add(a: i32, b: i32) -> i32           no overloading/default args
    //   C#:      int Add(int a, int b)                   params int[] for variadic
    //   C++ returns std::pair or struct for multiple values; Python returns tuple.
    return 0;
}