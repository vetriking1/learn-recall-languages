// ============================================================
// Topic:  Console Output & Input
// Summary: cout/cin, endl vs '\n', getline, ignore, setprecision.
// Run:     g++ -std=c++17 cpp/06_io.cpp -o cpp/06_io && cpp/06_io
// Note:    This file reads from the keyboard. When piping input use:
//          echo Vetri | cpp/06_io
//          (printf "Vetri\n5\n" | cpp/06_io  on Unix for both prompts)
// ============================================================

#include <iostream>
#include <iomanip>
#include <string>

int main() {
    // ----- 1. Basic output -----
    std::cout << "Hello, world" << std::endl;
    // Output: Hello, world

    // ----- 2. Printing multiple values -----
    std::cout << "a" << " " << "b" << " " << "c" << std::endl;
    // Output: a b c

    // ----- 3. endl vs '\n' -----
    // endl flushes the buffer AND adds newline; '\n' just adds newline (often faster).
    std::cout << "no newline";
    std::cout << "!! ";
    std::cout << "next\n";
    // Output: no newline!! next

    // ----- 4. Formatted output -----
    std::string name = "Vetri";
    int age = 22;
    std::cout << name << " is " << age << std::endl;
    // Output: Vetri is 22
    std::cout << std::fixed << std::setprecision(2) << 3.14159 << std::endl;
    // Output: 3.14

    // ----- 5. Reading a word with cin (stops at whitespace) -----
    std::cout << "Enter your name: ";
    std::string user_name;
    std::cin >> user_name;
    std::cout << "Hi " << user_name << "!" << std::endl;
    // Example (input "Vetri"):  Hi Vetri!

    // ----- 6. getline — read a full line (including spaces) -----
    std::cout << "Enter a phrase: ";
    std::cin.ignore();  // discard leftover '\n' from previous cin >>
    std::string phrase;
    std::getline(std::cin, phrase);
    std::cout << "You said: " << phrase << std::endl;
    // Example (input "hello world"):  You said: hello world

    // ----- 7. Converting input to a number -----
    std::cout << "Enter a number: ";
    int number;
    std::cin >> number;
    std::cout << "Doubled: " << number * 2 << std::endl;
    // Example (input "5"):  Doubled: 10

    // Cross-language note:
    //   C++ std::cout       == Python print()     == TS console.log()
    //   C++ std::cin >>     == Python input() split on whitespace
    //   C++ std::getline()  == Python input() for full line
    //   C++ std::setprecision == Python f"{x:.2f}" == TS toFixed(2)
    //   Always parse/cast: cin >> int for math; input() in Python also returns str.
    return 0;
}