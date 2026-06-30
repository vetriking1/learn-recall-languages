// ============================================================
// Topic:  Arrays / Vectors  (FOCUS: methods & operations)
// Summary: vector create, add, remove, sort, reverse, find, transform.
// Run:     g++ -std=c++17 cpp/09_arrays.cpp -o cpp/09_arrays && cpp/09_arrays
//
// KEY DIFFERENCE the user cares about:
//   C++: v.push_back(x), v.pop_back()   |   Python: l.append(x), l.pop()
//   C++: std::vector (dynamic array)    |   TS: Array / Python: list
// ============================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <string>

int main() {
    // ----- 1. Create & access -----
    std::vector<int> v = {10, 20, 30};
    std::cout << v[0] << std::endl;
    // Output: 10
    std::cout << v[v.size() - 1] << std::endl;
    // Output: 30
    std::cout << v.size() << std::endl;
    // Output: 3

    // ----- 2. Add to END -----
    v.push_back(40);
    for (int x : v) std::cout << x << " ";
    std::cout << std::endl;
    // Output: 10 20 30 40
    v.insert(v.end(), {50, 60});
    for (int x : v) std::cout << x << " ";
    std::cout << std::endl;
    // Output: 10 20 30 40 50 60

    // ----- 3. Add at specific index -----
    v.insert(v.begin(), 5);
    for (int x : v) std::cout << x << " ";
    std::cout << std::endl;
    // Output: 5 10 20 30 40 50 60

    // ----- 4. Remove from END -----
    v.pop_back();
    for (int x : v) std::cout << x << " ";
    std::cout << std::endl;
    // Output: 5 10 20 30 40 50

    // ----- 5. Remove from FRONT -----
    v.erase(v.begin());
    for (int x : v) std::cout << x << " ";
    std::cout << std::endl;
    // Output: 10 20 30 40 50

    // ----- 6. Remove by VALUE -----
    auto it = std::find(v.begin(), v.end(), 30);
    if (it != v.end()) v.erase(it);
    for (int x : v) std::cout << x << " ";
    std::cout << std::endl;
    // Output: 10 20 40 50

    // ----- 7. Search / membership -----
    std::cout << std::boolalpha
              << (std::find(v.begin(), v.end(), 20) != v.end()) << std::endl;
    // Output: true   | Python: 20 in l   TS: l.includes(20)
    auto pos = std::find(v.begin(), v.end(), 40);
    std::cout << (pos - v.begin()) << std::endl;
    // Output: 2   | Python: l.index(40)   TS: l.indexOf(40)

    // ----- 8. Transform (like Python list comp / TS arr.map) -----
    std::vector<int> nums = {1, 2, 3, 4};
    std::vector<int> doubled(nums.size());
    std::transform(nums.begin(), nums.end(), doubled.begin(),
                   [](int x) { return x * 2; });
    for (int x : doubled) std::cout << x << " ";
    std::cout << std::endl;
    // Output: 2 4 6 8

    std::vector<int> evens;
    std::copy_if(nums.begin(), nums.end(), std::back_inserter(evens),
                 [](int x) { return x % 2 == 0; });
    for (int x : evens) std::cout << x << " ";
    std::cout << std::endl;
    // Output: 2 4

    int total = std::accumulate(nums.begin(), nums.end(), 0);
    std::cout << total << std::endl;
    // Output: 10   | Python: sum(nums)   TS: nums.reduce(...)

    // ----- 9. Sort -----
    std::vector<int> vals = {3, 1, 4, 1, 5};
    std::sort(vals.begin(), vals.end());
    for (int x : vals) std::cout << x << " ";
    std::cout << std::endl;
    // Output: 1 1 3 4 5

    std::sort(vals.begin(), vals.end(), std::greater<int>());
    for (int x : vals) std::cout << x << " ";
    std::cout << std::endl;
    // Output: 5 4 3 1 1

    // ----- 10. Reverse -----
    std::reverse(v.begin(), v.end());
    for (int x : v) std::cout << x << " ";
    std::cout << std::endl;
    // Output: 50 40 20 10

    // ----- Quick reference table (C++ -> Python/TS) -----
    // v.size()              -> len(l) / l.length
    // v.push_back(x)        -> l.append(x) / l.push(x)
    // v.pop_back()          -> l.pop()          (both remove from END)
    // v.insert(v.begin(),x) -> l.insert(0, x)   / l.unshift(x)
    // v.erase(v.begin())    -> l.pop(0)         / l.shift()
    // std::find + erase     -> l.remove(x)      / splice after indexOf
    // std::find != end      -> x in l           / l.includes(x)
    // std::transform        -> [f(x) for x in l] / l.map(f)
    // std::accumulate       -> sum(l)           / l.reduce(...)
    // std::sort             -> l.sort()         / l.sort((a,b)=>a-b)
    return 0;
}