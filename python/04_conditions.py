# ============================================================
# Topic:  Conditions
# Summary: if / elif / else, ternary, truthiness, match.
# Run:     python python/04_conditions.py
# ============================================================

# ----- 1. Basic if / elif / else -----
# Indentation defines the block (no { } and no ( ) needed around the test).
age = 20
if age < 13:
    print("child")
elif age < 18:          # TS: else if
    print("teen")
else:
    print("adult")
# Output: adult

# ----- 2. Ternary (conditional expression) -----
# Python order reads "value_if_true if condition else value_if_false"
status = "pass" if age >= 18 else "fail"
print(status)           # Output: pass
# TS equivalent: const status = age >= 18 ? "pass" : "fail";

# ----- 3. Truthiness -----
# These are ALL falsy: 0, 0.0, "", [], {}, (), set(), None, False
if not []:
    print("empty list is falsy")    # Output: empty list is falsy
if "hello":
    print("non-empty string is truthy")  # Output: non-empty string is truthy

# ----- 4. Combining conditions -----
temp = 25
if temp > 20 and temp < 30:
    print("comfortable")            # Output: comfortable

# ----- 5. match / case (Python 3.10+, like TS switch) -----
command = "start"
match command:
    case "start":
        print("starting")          # Output: starting
    case "stop":
        print("stopping")
    case _:                         # default case (TS: default)
        print("unknown")

# Cross-language note:
#   No parentheses/braces in Python — indentation is the block.
#   Ternary word order is reversed vs TS (`a if cond else b` vs `cond ? a : b`).
