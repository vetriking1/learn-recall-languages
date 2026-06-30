// ============================================================
// Practice: Arrays
// Summary: max/min, sum/average, in-place reverse, remove dups.
// Run:     g++ -std=c++17 practice/cpp/arrays.cpp -o practice/cpp/arrays && practice/cpp/arrays
// ============================================================

#include <iostream>
#include <vector>
#include <utility>

// ----- 1. Max and min of a vector -----
std::pair<int, int> maxMin(const std::vector<int>& arr) {
    int mx = arr[0], mn = arr[0];
    for (int x : arr) {
        if (x > mx) mx = x;
        if (x < mn) mn = x;
    }
    return {mx, mn};
}

// ----- 2. Sum and average -----
std::pair<int, double> sumAvg(const std::vector<int>& arr) {
    int total = 0;
    for (int x : arr) total += x;
    return {total, (double)total / arr.size()};
}

// ----- 3. Reverse in place (two-pointer swap) -----
void reverseInPlace(std::vector<int>& arr) {
    int i = 0, j = (int)arr.size() - 1;
    while (i < j) {
        std::swap(arr[i], arr[j]);
        i++;
        j--;
    }
}

// ----- 4. Remove duplicates from a SORTED vector -----
std::vector<int> removeDuplicates(const std::vector<int>& arr) {
    std::vector<int> result;
    for (int x : arr) {
        if (result.empty() || result.back() != x) result.push_back(x);
    }
    return result;
}

void printVec(const std::vector<int>& v) {
    std::cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        if (i) std::cout << ", ";
        std::cout << v[i];
    }
    std::cout << "]" << std::endl;
}

int main() {
    std::pair<int, int> mm = maxMin({3, 7, 1, 9, 2});
    std::cout << "(" << mm.first << ", " << mm.second << ")" << std::endl;   // (9, 1)
    std::pair<int, double> sa = sumAvg({10, 20, 30, 40});
    std::cout << "(" << sa.first << ", " << sa.second << ")" << std::endl;   // (100, 25)
    std::vector<int> v = {1, 2, 3, 4, 5};
    reverseInPlace(v);
    printVec(v);                                                  // [5, 4, 3, 2, 1]
    printVec(removeDuplicates({1, 1, 2, 2, 3, 4, 4, 5}));         // [1, 2, 3, 4, 5]
    return 0;
}
