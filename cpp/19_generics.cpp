// ============================================================
// Topic:  Generics / Templates  (FOCUS: function & class templates, typename T)
// Summary: Compile-time polymorphism — templates replace runtime generics.
// Run:     g++ -std=c++17 cpp/19_generics.cpp -o cpp/19_generics && cpp/19_generics
//
// KEY DIFFERENCES:
//   C++:     templates (function/class), typename T, specialization
//   Java:    generics with type erasure, bounded wildcards <? extends T>
//   C#:      generics <T>, constraints where T : IComparable
//   Rust:    generics + traits, impl<T>, monomorphization
//   Python:  typing.TypeVar, no true generics at runtime
//   TS:      generics <T>, conditional & mapped types
// ============================================================

#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

// ----- Function template — swap two values of any comparable type -----
template <typename T>
void swap_values(T& left, T& right) {
    T temp = std::move(left);
    left = std::move(right);
    right = std::move(temp);
}

// ----- Function template — std::max style comparison -----
template <typename T>
T max_of(const T& left, const T& right) {
    return (left > right) ? left : right;
}

// ----- Class template — single type parameter -----
template <typename T>
class Box {
    T value_;

public:
    explicit Box(T value) : value_(std::move(value)) {}

    const T& get() const { return value_; }
};

// ----- Class template — multiple type parameters -----
template <typename T, typename U>
class Pair {
    T first_;
    U second_;

public:
    Pair(T first, U second) : first_(std::move(first)), second_(std::move(second)) {}

    const T& first() const { return first_; }
    const U& second() const { return second_; }
};

// ----- Class template — container holding homogeneous items -----
template <typename T>
class ItemBag {
    std::vector<T> items_;

public:
    void add(T item) { items_.push_back(std::move(item)); }

    std::size_t count() const { return items_.size(); }
};

int main() {
    // ----- 1. Function template — swap two ints -----
    int a = 1;
    int b = 2;
    swap_values(a, b);
    std::cout << "swap: " << a << " " << b << std::endl;
    // Output: swap: 2 1

    // ----- 2. Class template — Box<std::string> -----
    Box<std::string> greeting_box("hello");
    std::cout << "box: " << greeting_box.get() << std::endl;
    // Output: box: hello

    // ----- 3. std::max style — max_of template (mirrors std::max<int>) -----
    std::cout << "max: " << max_of(9, 4) << std::endl;
    (void)std::max(9, 4);  // std::max from <algorithm> — same semantics as max_of
    // Output: max: 9

    // ----- 4. Multiple template params — Pair<int, std::string> -----
    Pair<int, std::string> labeled_pair(1, "two");
    std::cout << "pair: " << labeled_pair.first() << " " << labeled_pair.second() << std::endl;
    // Output: pair: 1 two

    // ----- 5. ItemBag — count stored elements -----
    ItemBag<int> bag;
    bag.add(10);
    bag.add(20);
    bag.add(30);
    std::cout << "items: " << bag.count() << std::endl;
    // Output: items: 3

    return 0;
}