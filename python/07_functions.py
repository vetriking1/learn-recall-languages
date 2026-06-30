# ============================================================
# Topic:  Functions
# Summary: def, parameters, defaults, *args/**kwargs, return, lambda.
# Run:     python python/07_functions.py
# ============================================================

# ----- 1. Basic function -----
def greet(name):
    return f"Hello, {name}"
print(greet("Vetri"))        # Output: Hello, Vetri

# ----- 2. Type hints (optional; TS makes these mandatory-ish) -----
def add(a: int, b: int) -> int:
    return a + b
print(add(2, 3))             # Output: 5

# ----- 3. Default parameters -----
def power(base, exp=2):      # exp defaults to 2
    return base ** exp
print(power(5))              # Output: 25
print(power(5, 3))           # Output: 125

# ----- 4. Keyword arguments (call by name, any order) -----
def make_user(name, age):
    return f"{name}/{age}"
print(make_user(age=22, name="Vetri"))   # Output: Vetri/22

# ----- 5. *args -> variable positional args (TS: ...rest) -----
def total(*numbers):
    return sum(numbers)
print(total(1, 2, 3, 4))     # Output: 10

# ----- 6. **kwargs -> variable keyword args (TS: options object) -----
def describe(**info):
    return info
print(describe(name="Vetri", role="dev"))
# Output: {'name': 'Vetri', 'role': 'dev'}

# ----- 7. Returning multiple values (as a tuple) -----
def min_max(nums):
    return min(nums), max(nums)
low, high = min_max([4, 1, 9, 2])
print(low, high)             # Output: 1 9

# ----- 8. Lambda (anonymous function; TS: arrow function) -----
square = lambda x: x * x
print(square(6))             # Output: 36
# Common use: as a key/callback
nums = [3, 1, 2]
print(sorted(nums, key=lambda x: -x))   # Output: [3, 2, 1]

# Cross-language note:
#   Python `def f(x): ...`        == TS `function f(x) { ... }`
#   Python `lambda x: x*x`        == TS `(x) => x*x`
#   Python returns a tuple for "multiple returns"; TS returns an array/object.
