// ============================================================
// Topic:  Encapsulation
// Summary: Hide state behind methods; validate changes; expose read-only views.
// Run:     dotnet script csharp/11_encapsulation.cs
// ============================================================

using System;

var acct = new BankAccount("Vetri", 100);
acct.Deposit(50);
Console.WriteLine($"Balance: {acct.Balance}"); // Output: Balance: 150
acct.Withdraw(30);
Console.WriteLine($"Balance: {acct.Balance}"); // Output: Balance: 120
if (!acct.Withdraw(1000))
{
    Console.WriteLine("Insufficient funds");    // Output: Insufficient funds
}
Console.WriteLine($"Balance: {acct.Balance}"); // Output: Balance: 120
// acct.Balance = 999; // compile error: the set accessor is private

class BankAccount
{
    // auto-property with a PRIVATE setter: readable outside, writable only inside
    public string Owner { get; }
    public int Balance { get; private set; }

    public BankAccount(string owner, int balance)
    {
        Owner = owner;
        Balance = balance;
    }

    // ----- controlled mutation: validate before changing state -----
    public void Deposit(int amount)
    {
        if (amount > 0) Balance += amount;
    }

    public bool Withdraw(int amount)
    {
        if (amount > Balance) return false; // reject
        Balance -= amount;
        return true;
    }
}

// Cross-language note:
//   C# properties replace getter/setter boilerplate: `{ get; private set; }` is a
//   read-only-from-outside view with internal mutation. `private` is compiler-enforced.
//   Validation lives in Deposit/Withdraw so the balance invariant can't be bypassed.
