# ============================================================
# Topic:  Strings  (FOCUS: methods & operations)
# Summary: indexing, slicing, length, case, search, split/join, format.
# Run:     python python/08_strings.py
#
# KEY DIFFERENCE the user cares about:
#   Python: len(s), s.lower()      |   TS: s.length, s.toLowerCase()
# ============================================================

s = "Hello, World"

# ----- 1. Length -----
print(len(s))                # 12     | TS: s.length  (Python uses len(s), NOT s.length!)

# ----- 2. Indexing & negative indexing -----
print(s[0])                  # H      | TS: s[0]
print(s[-1])                 # d      | TS: s[s.length - 1]  (no negatives in TS)

# ----- 3. Slicing  s[start:stop:step]  (TS: s.slice(start, stop)) -----
print(s[0:5])                # Hello
print(s[7:])                 # World
print(s[:5])                 # Hello
print(s[::-1])               # dlroW ,olleH   (reverse; TS has no slice-reverse)

# ----- 4. Case methods -----
print(s.lower())             # hello, world   | TS: s.toLowerCase()
print(s.upper())             # HELLO, WORLD   | TS: s.toUpperCase()
print("hi there".title())    # Hi There       | TS: no direct equiv
print("hi".capitalize())     # Hi

# ----- 5. Search / test -----
print(s.find("World"))       # 7   (index, -1 if missing) | TS: s.indexOf("World")
print("World" in s)          # True                        | TS: s.includes("World")
print(s.startswith("Hello")) # True                        | TS: s.startsWith("Hello")
print(s.endswith("World"))   # True                        | TS: s.endsWith("World")
print(s.count("l"))          # 3   (count occurrences)

# ----- 6. Modify (strings are IMMUTABLE; methods return NEW strings) -----
print(s.replace("World", "Vetri"))   # Hello, Vetri  | TS: s.replace(...) / replaceAll
print("  pad  ".strip())             # 'pad'         | TS: s.trim()
print("a,b,c".split(","))            # ['a', 'b', 'c'] | TS: "a,b,c".split(",")
print("-".join(["a", "b", "c"]))     # a-b-c         | TS: ["a","b","c"].join("-")

# ----- 7. Formatting -----
name, age = "Vetri", 22
print(f"{name} is {age}")            # Vetri is 22   | TS: `${name} is ${age}`
print("{} is {}".format(name, age))  # Vetri is 22   (older style)

# ----- 8. Char <-> code -----
print(ord("A"))              # 65   | TS: "A".charCodeAt(0)
print(chr(66))               # B    | TS: String.fromCharCode(66)

# ----- Quick reference table (Python -> TS) -----
# len(s)            -> s.length
# s.lower()         -> s.toLowerCase()
# s.upper()         -> s.toUpperCase()
# s.find(x)         -> s.indexOf(x)
# x in s            -> s.includes(x)
# s.strip()         -> s.trim()
# s.replace(a,b)    -> s.replaceAll(a,b)
# s.split(",")      -> s.split(",")
# "-".join(list)    -> list.join("-")
# s[a:b]            -> s.slice(a,b)
