// ============================================================
// Practice: Strings
// Summary: manual reverse, palindrome check, char counting.
// Run:     g++ -std=c++17 practice/cpp/strings.cpp -o practice/cpp/strings && practice/cpp/strings
// ============================================================

#include <iostream>
#include <string>
#include <cctype>
#include <tuple>

// ----- 1. Reverse a string without std::reverse -----
std::string reverseString(const std::string& s) {
    std::string result;
    for (char ch : s) result = ch + result; // prepend each char
    return result;
}

// ----- 2. Palindrome check (ignore case and non-alphanumerics) -----
bool isPalindrome(const std::string& s) {
    std::string cleaned;
    for (char c : s)
        if (std::isalnum((unsigned char)c)) cleaned += std::tolower((unsigned char)c);
    int i = 0, j = (int)cleaned.size() - 1;
    while (i < j) {
        if (cleaned[i] != cleaned[j]) return false;
        i++;
        j--;
    }
    return true;
}

// ----- 3. Count vowels, consonants, special characters -----
std::tuple<int, int, int> countChars(const std::string& s) {
    int vowels = 0, consonants = 0, special = 0;
    for (char c : s) {
        char lc = std::tolower((unsigned char)c);
        if (lc >= 'a' && lc <= 'z') {
            if (std::string("aeiou").find(lc) != std::string::npos) vowels++;
            else consonants++;
        } else {
            special++;
        }
    }
    return {vowels, consonants, special};
}

int main() {
    std::cout << reverseString("hello") << std::endl;                      // olleh
    std::cout << std::boolalpha;
    std::cout << isPalindrome("A man a plan a canal Panama") << std::endl; // true
    std::cout << isPalindrome("hello") << std::endl;                       // false
    std::tuple<int, int, int> cc = countChars("Hello, World! 123");
    std::cout << "(" << std::get<0>(cc) << ", " << std::get<1>(cc) << ", "
              << std::get<2>(cc) << ")" << std::endl;                      // (3, 7, 7)
    return 0;
}
