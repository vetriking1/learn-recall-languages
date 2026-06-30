# ============================================================
# Topic:  Encapsulation
# Summary: Hide state behind methods; validate changes; expose read-only views.
# Run:     python python/11_encapsulation.py
# ============================================================

class BankAccount:
    def __init__(self, owner, balance=0):
        self.owner = owner
        self.__balance = balance      # __ = "private" (name-mangled to _BankAccount__balance)

    # ----- read-only accessor via @property (no setter = can't assign) -----
    @property
    def balance(self):
        return self.__balance

    # ----- controlled mutation: validate before changing state -----
    def deposit(self, amount):
        if amount > 0:
            self.__balance += amount

    def withdraw(self, amount):
        if amount > self.__balance:
            return False              # reject: not enough money
        self.__balance -= amount
        return True


acct = BankAccount("Vetri", 100)
acct.deposit(50)
print("Balance:", acct.balance)       # Output: Balance: 150
acct.withdraw(30)
print("Balance:", acct.balance)       # Output: Balance: 120
if not acct.withdraw(1000):
    print("Insufficient funds")       # Output: Insufficient funds
print("Balance:", acct.balance)       # Output: Balance: 120
# acct.balance = 999  # AttributeError: property 'balance' has no setter

# Cross-language note:
#   Python has no real access control — `__name` only name-mangles by convention.
#   @property exposes a read-only view; the invariant (balance >= 0) lives in the methods.
#   Other languages enforce privacy with keywords (private) checked by the compiler.
