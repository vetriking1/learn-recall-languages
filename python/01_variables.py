# ============================================================
# Topic:  Variables
# Summary: How to declare, name, rebind and annotate variables.
# Run:     python python/01_variables.py
# ============================================================

# ----- 1. Basic declaration -----
# Python has no keyword (no let/const/var). Just assign.
name = "Vetri"
age = 22
print(name, age)          # Output: Vetri 22

# ----- 2. Reassigning (everything is mutable rebind) -----
# Unlike TS `const`, Python has no real constant. Convention: UPPERCASE = "don't change me".
PI = 3.14159               # by convention a constant
score = 10
score = 20                 # totally fine to rebind
print(score)               # Output: 20

# ----- 3. Multiple assignment -----
x, y, z = 1, 2, 3
a = b = c = 0              # all point to the same value
print(x, y, z, a, b, c)   # Output: 1 2 3 0 0 0

# ----- 4. Swapping (no temp variable needed) -----
x, y = y, x
print(x, y)               # Output: 2 1

# ----- 5. Type annotations (optional, not enforced at runtime) -----
# TS equivalent: let username: string = "abc"
username: str = "abc"
count: int = 5
print(username, count)    # Output: abc 5

# ----- 6. Naming rules -----
# snake_case is the Python convention (TS uses camelCase).
total_price = 99.5        # good
print(total_price)        # Output: 99.5

# ----- 7. Dynamic typing -----
# A variable can change type on rebind (TS would error without `any`).
thing = 5
thing = "now a string"
print(thing)              # Output: now a string

# Cross-language note:
#   Python:  name = "Vetri"
#   TS:      let name = "Vetri";  // or const name = "Vetri";
