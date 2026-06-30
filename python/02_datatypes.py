# ============================================================
# Topic:  Data Types
# Summary: Core built-in types, checking types, and converting.
# Run:     python python/02_datatypes.py
# ============================================================

# ----- 1. The core scalar types -----
an_int   = 42            # int          (TS: number)
a_float  = 3.14          # float        (TS: number)
a_str    = "hello"       # str          (TS: string)
a_bool   = True          # bool         (TS: boolean)  note: capital T/F
nothing  = None          # NoneType     (TS: null / undefined)
print(an_int, a_float, a_str, a_bool, nothing)
# Output: 42 3.14 hello True None

# ----- 2. Checking a type -----
# Python: type(x) or isinstance(x, T)   |   TS: typeof x
print(type(an_int))                  # Output: <class 'int'>
print(type(a_str))                   # Output: <class 'str'>
print(isinstance(a_bool, bool))      # Output: True

# ----- 3. Collection types (covered deeper in later files) -----
a_list  = [1, 2, 3]      # list   -> like a TS array []
a_tuple = (1, 2, 3)      # tuple  -> immutable, no direct TS equivalent
a_dict  = {"k": "v"}     # dict   -> like a TS object / Map
a_set   = {1, 2, 3}      # set    -> like a TS Set
print(a_list, a_tuple, a_dict, a_set)
# Output: [1, 2, 3] (1, 2, 3) {'k': 'v'} {1, 2, 3}

# ----- 4. Conversion / casting -----
print(int("10") + 5)     # str  -> int   Output: 15
print(str(10) + "5")     # int  -> str   Output: 105
print(float("3.5"))      # str  -> float Output: 3.5
print(bool(0), bool(""), bool(1))   # falsy/truthy  Output: False False True

# ----- 5. Numeric detail Python has and TS does not -----
print(7 // 2)            # integer division   Output: 3
print(7 / 2)             # float division      Output: 3.5
print(2 ** 10)           # power               Output: 1024
print(10 % 3)            # modulo              Output: 1

# Cross-language note:
#   Python distinguishes int vs float; TS has only `number` (a 64-bit float).
#   Python None  ~=  TS null/undefined (TS has TWO "empty" values, Python has one).
