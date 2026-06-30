// ============================================================
// Topic:  Encapsulation
// Summary: Hide state behind methods; validate changes; expose read-only views.
// Run:     cd typescript && npx ts-node 11_encapsulation.ts
// ============================================================

class BankAccount {
  private balanceAmount: number; // `private` is enforced by the TS compiler

  // shorthand: `public readonly owner` declares + assigns the field
  constructor(public readonly owner: string, initial: number) {
    this.balanceAmount = initial;
  }

  // ----- read-only accessor (getter, no setter) -----
  get balance(): number {
    return this.balanceAmount;
  }

  // ----- controlled mutation: validate before changing state -----
  deposit(amount: number): void {
    if (amount > 0) this.balanceAmount += amount;
  }

  withdraw(amount: number): boolean {
    if (amount > this.balanceAmount) return false; // reject
    this.balanceAmount -= amount;
    return true;
  }
}

const acct = new BankAccount("Vetri", 100);
acct.deposit(50);
console.log("Balance:", acct.balance); // Output: Balance: 150
acct.withdraw(30);
console.log("Balance:", acct.balance); // Output: Balance: 120
if (!acct.withdraw(1000)) {
  console.log("Insufficient funds");   // Output: Insufficient funds
}
console.log("Balance:", acct.balance); // Output: Balance: 120
// acct.balanceAmount = 999; // compile error: 'balanceAmount' is private

// Cross-language note:
//   TS `private` is checked at COMPILE time only (the field is still there at runtime).
//   For true runtime privacy use a #field: `#balance`. `get balance()` is a read-only view.
//   `readonly` blocks reassignment after construction.
