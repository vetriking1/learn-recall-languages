// ============================================================
// Practice: Numbers
// Summary: prime check, multiplication table, Euclidean GCD.
// Run:     g++ -std=c++17 practice/cpp/numbers.cpp -o practice/cpp/numbers && practice/cpp/numbers
// ============================================================

#include <iostream>

// ----- 1. Is a number prime? -----
bool isPrime(int n) {
    if (n < 2) return false;
    for (long long i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

// ----- 2. Multiplication table for n, 1..limit -----
void printTable(int n, int limit) {
    for (int i = 1; i <= limit; i++)
        std::cout << n << " x " << i << " = " << n * i << std::endl;
}

// ----- 3. GCD via the Euclidean algorithm -----
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    std::cout << std::boolalpha;
    std::cout << isPrime(7) << " " << isPrime(10) << std::endl; // true false
    printTable(7, 10);                                           // 7 x 1 = 7 ... 7 x 10 = 70
    std::cout << gcd(48, 18) << std::endl;                       // 6
    return 0;
}
