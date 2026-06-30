# ============================================================
# Topic:  Console Output & Input
# Summary: print() variations and input() from the user.
# Run:     python python/06_io.py
# Note:    This file reads from the keyboard. When piping input use:
#          echo "Vetri" | python python/06_io.py
# ============================================================

# ----- 1. Basic output -----
print("Hello, world")        # Output: Hello, world

# ----- 2. Printing multiple values (space-separated by default) -----
print("a", "b", "c")         # Output: a b c

# ----- 3. Custom separator and end -----
print("a", "b", "c", sep="-")        # Output: a-b-c
print("no newline", end="!! ")        # Output: no newline!! (no line break)
print("next")                         # Output: next

# ----- 4. f-strings (formatted output; TS: template literals) -----
name = "Vetri"
age = 22
print(f"{name} is {age}")             # Output: Vetri is 22
print(f"{3.14159:.2f}")               # Output: 3.14   (2 decimal places)

# ----- 5. Reading input (always returns a str) -----
# input(prompt) shows the prompt then waits for a line of text.
user_name = input("Enter your name: ")
print(f"Hi {user_name}!")
# Example (input "Vetri"):  Hi Vetri!

# ----- 6. Converting input to a number -----
# input() gives text, so cast it for math.
raw = input("Enter a number: ")
number = int(raw)            # int("5") -> 5
print(f"Doubled: {number * 2}")
# Example (input "5"):  Doubled: 10

# Cross-language note:
#   Python print()          == TS console.log()
#   Python input("...")     == TS prompt() (browser) / readline (node) — and ALWAYS
#                              returns a string, so cast with int()/float() for math.
