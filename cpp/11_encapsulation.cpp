// ============================================================
// Topic:  Encapsulation
// Summary: Hide state behind methods; validate changes; expose read-only views.
// Run:     g++ -std=c++17 cpp/11_encapsulation.cpp -o cpp/11_encapsulation && cpp/11_encapsulation
// ============================================================

#include <iostream>
#include <string>

class BankAccount {
private:
    std::string owner;
    int balance;   // hidden: not accessible outside the class

public:
    BankAccount(const std::string& owner, int balance) : owner(owner), balance(balance) {}

    // ----- read-only accessor (const method) -----
    int getBalance() const { return balance; }

    // ----- controlled mutation: validate before changing state -----
    void deposit(int amount) {
        if (amount > 0) balance += amount;
    }

    bool withdraw(int amount) {
        if (amount > balance) return false; // reject
        balance -= amount;
        return true;
    }
};

int main() {
    BankAccount acct("Vetri", 100);
    acct.deposit(50);
    std::cout << "Balance: " << acct.getBalance() << std::endl; // Output: Balance: 150
    acct.withdraw(30);
    std::cout << "Balance: " << acct.getBalance() << std::endl; // Output: Balance: 120
    if (!acct.withdraw(1000)) {
        std::cout << "Insufficient funds" << std::endl;          // Output: Insufficient funds
    }
    std::cout << "Balance: " << acct.getBalance() << std::endl; // Output: Balance: 120
    // acct.balance = 999; // compile error: 'balance' is private
    return 0;
}

// Cross-language note:
//   C++ `private:` is compiler-enforced. A `const` getter promises not to mutate.
//   The validating deposit/withdraw are the only way to change balance, protecting
//   the invariant (balance never goes negative).
