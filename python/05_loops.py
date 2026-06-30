# ============================================================
# Topic:  Loops
# Summary: for, while, range, enumerate, break/continue, comprehensions.
# Run:     python python/05_loops.py
# ============================================================

# ----- 1. for over a range -----
# range(stop) -> 0..stop-1   |  TS: for (let i=0; i<3; i++)
for i in range(3):
    print(i, end=" ")        # Output: 0 1 2
print()

# range(start, stop, step)
for i in range(2, 11, 2):
    print(i, end=" ")        # Output: 2 4 6 8 10
print()

# ----- 2. for over a collection (for..of in TS) -----
fruits = ["apple", "banana", "cherry"]
for fruit in fruits:
    print(fruit, end=" ")    # Output: apple banana cherry
print()

# ----- 3. enumerate -> index + value (TS: arr.entries()) -----
for index, fruit in enumerate(fruits):
    print(f"{index}:{fruit}", end=" ")   # Output: 0:apple 1:banana 2:cherry
print()

# ----- 4. while loop -----
n = 3
while n > 0:
    print(n, end=" ")        # Output: 3 2 1
    n -= 1
print()

# ----- 5. break and continue -----
for i in range(10):
    if i == 3:
        continue             # skip 3
    if i == 6:
        break                # stop at 6
    print(i, end=" ")        # Output: 0 1 2 4 5
print()

# ----- 6. for...else (Python-only: runs if loop didn't break) -----
for i in range(3):
    pass
else:
    print("loop finished without break")  # Output: loop finished without break

# ----- 7. List comprehension (concise build; TS: arr.map/filter) -----
squares = [x * x for x in range(5)]
print(squares)               # Output: [0, 1, 4, 9, 16]
evens = [x for x in range(10) if x % 2 == 0]
print(evens)                 # Output: [0, 2, 4, 6, 8]

# Cross-language note:
#   Python `for x in coll` == TS `for (const x of coll)`.
#   `range()` replaces the C-style counter loop. No i++ — range handles stepping.
