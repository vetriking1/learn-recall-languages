// ============================================================
// Topic:  Strings  (FOCUS: methods & operations)
// Summary: size, substr, find, case, replace, erase, split, join, repeat.
// Run:     g++ -std=c++17 cpp/08_strings.cpp -o cpp/08_strings && cpp/08_strings
//
// KEY DIFFERENCE the user cares about:
//   C++: s.size(), no s.contains() until C++23 — use s.find(x) != npos
//   Python: len(s), s.lower()   |   TS: s.length, s.toLowerCase()
// ============================================================

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cctype>

std::string to_lower(const std::string& s) {
    std::string result = s;
    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    return result;
}

std::string to_upper(const std::string& s) {
    std::string result = s;
    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c) { return std::toupper(c); });
    return result;
}

bool contains(const std::string& s, const std::string& sub) {
    return s.find(sub) != std::string::npos;  // C++23: s.contains(sub)
}

std::vector<std::string> split(const std::string& s, char delim) {
    std::vector<std::string> parts;
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        parts.push_back(item);
    }
    return parts;
}

std::string join(const std::vector<std::string>& parts, const std::string& sep) {
    std::ostringstream oss;
    for (size_t i = 0; i < parts.size(); ++i) {
        if (i > 0) oss << sep;
        oss << parts[i];
    }
    return oss.str();
}

std::string repeat(const std::string& s, int times) {
    std::string result;
    result.reserve(s.size() * times);
    for (int i = 0; i < times; ++i) result += s;
    return result;
}

int main() {
    std::string s = "Hello, World";

    // ----- 1. Length -----
    std::cout << s.size() << std::endl;
    // Output: 12   (also s.length() — same)   | Python: len(s)   TS: s.length

    // ----- 2. Indexing (no negative indices like Python) -----
    std::cout << s[0] << std::endl;
    // Output: H
    std::cout << s[s.size() - 1] << std::endl;
    // Output: d

    // ----- 3. Substring -----
    std::cout << s.substr(0, 5) << std::endl;
    // Output: Hello
    std::cout << s.substr(7) << std::endl;
    // Output: World

    // ----- 4. Case -----
    std::cout << to_lower(s) << std::endl;
    // Output: hello, world   | Python: s.lower()   TS: s.toLowerCase()
    std::cout << to_upper(s) << std::endl;
    // Output: HELLO, WORLD   | Python: s.upper()   TS: s.toUpperCase()

    // ----- 5. Search / test -----
    std::cout << s.find("World") << std::endl;
    // Output: 7   (npos if missing)   | Python: s.find()   TS: indexOf()
    std::cout << std::boolalpha << contains(s, "World") << std::endl;
    // Output: true   | Python: "World" in s   TS: s.includes("World")
    std::cout << s.rfind('l') << std::endl;
    // Output: 10   (last index of 'l')

    // ----- 6. Modify (std::string is mutable unlike Python str) -----
    std::string replaced = s;
    size_t pos = replaced.find("World");
    if (pos != std::string::npos) replaced.replace(pos, 5, "Vetri");
    std::cout << replaced << std::endl;
    // Output: Hello, Vetri

    std::string padded = "  pad  ";
    padded.erase(0, padded.find_first_not_of(' '));
    padded.erase(padded.find_last_not_of(' ') + 1);
    std::cout << padded << std::endl;
    // Output: pad   (manual trim — or no trim in std until C++17)

    // ----- 7. Split & join -----
    auto parts = split("a,b,c", ',');
    std::cout << join(parts, "-") << std::endl;
    // Output: a-b-c   | Python: "-".join(s.split(","))   TS: arr.join("-")

    // ----- 8. Repeat -----
    std::cout << repeat("ha", 3) << std::endl;
    // Output: hahaha   | Python: "ha" * 3

    // ----- 9. Erase -----
    std::string text = "abcdef";
    text.erase(2, 2);  // erase 2 chars at index 2
    std::cout << text << std::endl;
    // Output: abef

    // ----- Quick reference table (C++ -> Python/TS) -----
    // s.size()                    -> len(s) / s.length
    // to_lower(s) / to_upper(s)   -> s.lower() / s.upper() / toLowerCase / toUpperCase
    // s.find(x) != npos           -> x in s / s.includes(x)
    // s.replace(pos, len, new)    -> s.replace(a, b) / replaceAll
    // split(s, ',')               -> s.split(",") / s.split(",")
    // join(vec, "-")              -> "-".join(list) / list.join("-")
    // s.substr(a, b)              -> s[a:b] / s.slice(a, b)
    return 0;
}