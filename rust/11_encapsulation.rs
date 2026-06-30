// ============================================================
// Topic:  Encapsulation  (Rust hides state at the MODULE boundary)
// Summary: Private struct fields + pub methods that validate changes.
// Run:     rustc rust/11_encapsulation.rs -o rust/11_encapsulation && rust/11_encapsulation
// ============================================================

mod bank {
    // ----- struct fields are private to the module unless marked `pub` -----
    #[allow(dead_code)] // `owner` is shown as a pub field but not read in this demo
    pub struct BankAccount {
        pub owner: String,
        balance: i32, // private: code outside `bank` cannot touch this
    }

    impl BankAccount {
        pub fn new(owner: &str, balance: i32) -> BankAccount {
            BankAccount { owner: owner.to_string(), balance }
        }

        // read-only accessor (method shares the field's name — that's fine)
        pub fn balance(&self) -> i32 {
            self.balance
        }

        // ----- controlled mutation: validate before changing state -----
        pub fn deposit(&mut self, amount: i32) {
            if amount > 0 {
                self.balance += amount;
            }
        }

        pub fn withdraw(&mut self, amount: i32) -> bool {
            if amount > self.balance {
                return false; // reject
            }
            self.balance -= amount;
            true
        }
    }
}

use bank::BankAccount;

fn main() {
    let mut acct = BankAccount::new("Vetri", 100);
    acct.deposit(50);
    println!("Balance: {}", acct.balance()); // Output: Balance: 150
    acct.withdraw(30);
    println!("Balance: {}", acct.balance()); // Output: Balance: 120
    if !acct.withdraw(1000) {
        println!("Insufficient funds");       // Output: Insufficient funds
    }
    println!("Balance: {}", acct.balance()); // Output: Balance: 120
    // acct.balance = 999; // ERROR: field `balance` of struct `BankAccount` is private
}

// Cross-language note:
//   Rust privacy is per-MODULE, not per-class: items are private to their module
//   unless marked `pub`. So `balance` is hidden outside `mod bank`, while `owner` is open.
//   No getter/setter keywords — just a `pub fn` accessor. The compiler enforces all of this.
