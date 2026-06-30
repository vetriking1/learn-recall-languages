# ============================================================
# Topic:  Operators
# Summary: Arithmetic, comparison, logical, assignment operators.
# Run:     python python/03_operators.py
# ============================================================

# ----- 1. Arithmetic -----
print(5 + 2)    # 7
print(5 - 2)    # 3
print(5 * 2)    # 10
print(5 / 2)    # 2.5   (always float)
print(5 // 2)   # 2     (floor division; TS: Math.floor(5/2))
print(5 % 2)    # 1     (modulo)
print(5 ** 2)   # 25    (power; TS: 5 ** 2 too)

# ----- 2. Comparison (return bool) -----
print(5 == 5)   # True   (TS: === for strict equality)
print(5 != 3)   # True
print(5 > 3, 5 < 3, 5 >= 5, 5 <= 4)   # True False True False

# ----- 3. Logical -----
# Python uses words; TS uses symbols (&&, ||, !)
print(True and False)   # False   (TS: &&)
print(True or False)    # True    (TS: ||)
print(not True)         # False   (TS: !)

# ----- 4. Chained comparison (Python-only nicety) -----
x = 5
print(1 < x < 10)       # True   (TS needs: 1 < x && x < 10)

# ----- 5. Augmented assignment -----
n = 10
n += 5;  print(n)   # 15
n -= 3;  print(n)   # 12
n *= 2;  print(n)   # 24
n //= 5; print(n)   # 4
# Note: Python has NO ++ or -- operators (TS does). Use n += 1.

# ----- 6. Membership & identity (Python-only operators) -----
print(3 in [1, 2, 3])       # True   (TS: [1,2,3].includes(3))
print("a" in "cat")          # True   (TS: "cat".includes("a"))
print(None is None)          # True   (identity check)

# Cross-language note:
#   Equality: Python `==` compares values; TS `===` compares value+type strictly.
#   Increment: no `i++` in Python — write `i += 1`.
