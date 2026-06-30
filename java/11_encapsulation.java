// ============================================================
// Topic:  Encapsulation
// Summary: Hide state behind methods; validate changes; expose read-only views.
// Run:     java java/11_encapsulation.java   (Java 11+ single-file launch)
// ============================================================

public class Encapsulation {
    public static void main(String[] args) {
        BankAccount acct = new BankAccount("Vetri", 100);
        acct.deposit(50);
        System.out.println("Balance: " + acct.getBalance()); // Output: Balance: 150
        acct.withdraw(30);
        System.out.println("Balance: " + acct.getBalance()); // Output: Balance: 120
        if (!acct.withdraw(1000)) {
            System.out.println("Insufficient funds");          // Output: Insufficient funds
        }
        System.out.println("Balance: " + acct.getBalance()); // Output: Balance: 120
        // acct.balance = 999; // compile error: balance has private access
    }
}

class BankAccount {
    private String owner;  // hidden state
    private int balance;

    BankAccount(String owner, int balance) {
        this.owner = owner;
        this.balance = balance;
    }

    // ----- read-only accessor (getter, no public setter) -----
    public int getBalance() {
        return balance;
    }

    // ----- controlled mutation: validate before changing state -----
    public void deposit(int amount) {
        if (amount > 0) balance += amount;
    }

    public boolean withdraw(int amount) {
        if (amount > balance) return false; // reject
        balance -= amount;
        return true;
    }
}

// Cross-language note:
//   Java's classic pattern: `private` fields + public getters (and setters only when
//   needed). `private` is compiler-enforced. Providing a getter but no setter makes
//   balance read-only from outside, so deposit/withdraw guard the invariant.
