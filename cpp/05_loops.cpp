// ============================================================
// Topic:  Loops
// Summary: C-style for, range-for, while, break/continue, transform.
// Run:     g++ -std=c++17 cpp/05_loops.cpp -o cpp/05_loops && cpp/05_loops
// ============================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main() {
    // ----- 1. C-style for (counter loop — like TS for (let i=0; ...)) -----
    for (int i = 0; i < 3; ++i) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    // Output: 0 1 2

    for (int i = 2; i < 11; i += 2) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    // Output: 2 4 6 8 10

    // ----- 2. Range-for over a collection (like Python for x in coll / TS for..of) -----
    std::vector<std::string> fruits = {"apple", "banana", "cherry"};
    for (const auto& fruit : fruits) {
        std::cout << fruit << " ";
    }
    std::cout << std::endl;
    // Output: apple banana cherry

    // ----- 3. Index + value (like Python enumerate / TS arr.entries()) -----
    for (size_t index = 0; index < fruits.size(); ++index) {
        std::cout << index << ":" << fruits[index] << " ";
    }
    std::cout << std::endl;
    // Output: 0:apple 1:banana 2:cherry

    // ----- 4. while loop -----
    int n = 3;
    while (n > 0) {
        std::cout << n << " ";
        --n;
    }
    std::cout << std::endl;
    // Output: 3 2 1

    // ----- 5. break and continue -----
    for (int i = 0; i < 10; ++i) {
        if (i == 3) continue;  // skip 3
        if (i == 6) break;     // stop at 6
        std::cout << i << " ";
    }
    std::cout << std::endl;
    // Output: 0 1 2 4 5

    // ----- 6. Transform with lambda (like Python list comp / TS arr.map) -----
    std::vector<int> nums = {0, 1, 2, 3, 4};
    std::vector<int> squares(nums.size());
    std::transform(nums.begin(), nums.end(), squares.begin(),
                   [](int x) { return x * x; });
    for (int sq : squares) {
        std::cout << sq << " ";
    }
    std::cout << std::endl;
    // Output: 0 1 4 9 16

    std::vector<int> evens;
    for (int x : nums) {
        if (x % 2 == 0) evens.push_back(x);
    }
    for (int e : evens) {
        std::cout << e << " ";
    }
    std::cout << std::endl;
    // Output: 0 2 4

    // Cross-language note:
    //   C++:     for (int i=0; i<n; ++i)   for (auto& x : vec)   while (cond)
    //   Python:  for i in range(n)         for x in coll         while cond
    //   TS:      for (let i=0; i<n; i++)    for (const x of arr)  while (cond)
    //   Rust:    for i in 0..n              for x in &vec         while cond
    //   C#:      for (int i=0; i<n; i++)    foreach (var x in list) while (cond)
    //   C++ has no for-else (Python-only). Use std::transform + lambda instead of comprehensions.
    return 0;
}