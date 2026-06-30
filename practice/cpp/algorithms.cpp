// ============================================================
// Practice: Algorithms
// Summary: linear search, binary search, Fibonacci (iter + rec).
// Run:     g++ -std=c++17 practice/cpp/algorithms.cpp -o practice/cpp/algorithms && practice/cpp/algorithms
// ============================================================

#include <iostream>
#include <vector>

// ----- 1. Linear search -> index, or -1 if not found -----
int linearSearch(const std::vector<int>& arr, int target) {
    for (int i = 0; i < (int)arr.size(); i++)
        if (arr[i] == target) return i;
    return -1;
}

// ----- 2. Binary search on a SORTED vector -> index, or -1 -----
int binarySearch(const std::vector<int>& arr, int target) {
    int lo = 0, hi = (int)arr.size() - 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}

// ----- 3a. Fibonacci, iterative (N terms) -----
std::vector<long long> fibIterative(int n) {
    std::vector<long long> seq;
    long long a = 0, b = 1;
    for (int i = 0; i < n; i++) {
        seq.push_back(a);
        long long next = a + b;
        a = b;
        b = next;
    }
    return seq;
}

// ----- 3b. Fibonacci, recursive (nth term) -----
long long fibRecursive(int n) {
    if (n < 2) return n;
    return fibRecursive(n - 1) + fibRecursive(n - 2);
}

void printVec(const std::vector<long long>& v) {
    std::cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        if (i) std::cout << ", ";
        std::cout << v[i];
    }
    std::cout << "]" << std::endl;
}

int main() {
    std::cout << linearSearch({4, 2, 7, 1, 9, 3}, 7) << std::endl;  // 2
    std::cout << linearSearch({4, 2, 7, 1, 9, 3}, 5) << std::endl;  // -1
    std::cout << binarySearch({1, 3, 5, 7, 9, 11}, 7) << std::endl; // 3
    std::cout << binarySearch({1, 3, 5, 7, 9, 11}, 4) << std::endl; // -1
    printVec(fibIterative(10));                                      // [0, 1, 1, 2, 3, 5, 8, 13, 21, 34]
    std::vector<long long> rec;
    for (int i = 0; i < 10; i++) rec.push_back(fibRecursive(i));
    printVec(rec);                                                   // same
    return 0;
}
