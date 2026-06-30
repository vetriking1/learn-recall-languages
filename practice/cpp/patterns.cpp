// ============================================================
// Practice: Patterns
// Summary: right-angled triangle, centered pyramid.
// Run:     g++ -std=c++17 practice/cpp/patterns.cpp -o practice/cpp/patterns && practice/cpp/patterns
// ============================================================

#include <iostream>
#include <string>

// ----- 1. Right-angled triangle of stars -----
void rightTriangle(int n) {
    for (int i = 1; i <= n; i++)
        std::cout << std::string(i, '*') << std::endl;
}

// ----- 2. Centered pyramid of stars (height h) -----
void pyramid(int h) {
    for (int i = 1; i <= h; i++) {
        std::string spaces(h - i, ' ');
        std::string stars(2 * i - 1, '*');
        std::cout << spaces << stars << std::endl;
    }
}

int main() {
    std::cout << "Right triangle (N=5):" << std::endl;
    rightTriangle(5);
    // *
    // **
    // ***
    // ****
    // *****

    std::cout << "Pyramid (height=5):" << std::endl;
    pyramid(5);
    //     *
    //    ***
    //   *****
    //  *******
    // *********
    return 0;
}
