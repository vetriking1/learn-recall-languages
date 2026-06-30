// ============================================================
// Topic:  Strings  (FOCUS: methods & operations)
// Summary: length, indexing, slicing, case, search, split/join, format.
// Run:     npx ts-node typescript/08_strings.ts
//
// KEY DIFFERENCE the user cares about:
//   TS: s.length, s.toLowerCase()   |   Python: len(s), s.lower()
// ============================================================

const s = "Hello, World";

// ----- 1. Length (a PROPERTY, no parentheses; Python: len(s)) -----
console.log(s.length); // 12   ⚠ s.length NOT len(s)

// ----- 2. Indexing (no negative indexing like Python) -----
console.log(s[0]); // H     | Python: s[0]
console.log(s[s.length - 1]); // d     | Python: s[-1]   (TS has no s[-1])
console.log(s.charAt(0)); // H     (alternative)
console.log(s.at(-1)); // d     (.at() DOES allow negatives)

// ----- 3. Slicing -> s.slice(start, stop)  (Python: s[start:stop]) -----
console.log(s.slice(0, 5)); // Hello
console.log(s.slice(7)); // World
console.log(s.split("").reverse().join("")); // dlroW ,olleH (reverse; Python: s[::-1])

// ----- 4. Case methods -----
console.log(s.toLowerCase()); // hello, world   | Python: s.lower()
console.log(s.toUpperCase()); // HELLO, WORLD   | Python: s.upper()

// ----- 5. Search / test -----
console.log(s.indexOf("World")); // 7   (-1 if missing) | Python: s.find("World")
console.log(s.includes("World")); // true               | Python: "World" in s
console.log(s.startsWith("Hello")); // true             | Python: s.startswith(...)
console.log(s.endsWith("World")); // true               | Python: s.endswith(...)

// ----- 6. Modify (strings are IMMUTABLE; methods return NEW strings) -----
console.log(s.replace("World", "Vetri")); // Hello, Vetri | Python: s.replace(...)
console.log(s.replaceAll("l", "L")); // HeLLo, WorLd
console.log("  pad  ".trim()); // 'pad'             | Python: s.strip()
console.log("a,b,c".split(",")); // [ 'a', 'b', 'c' ] | Python: "a,b,c".split(",")
console.log(["a", "b", "c"].join("-")); // a-b-c        | Python: "-".join([...])
console.log("hi".repeat(3)); // hihihi             | Python: "hi" * 3
console.log("5".padStart(3, "0")); // 005           | Python: "5".zfill(3)

// ----- 7. Formatting (template literals; Python: f-strings) -----
const name = "Vetri",
  age = 22;
console.log(`${name} is ${age}`); // Vetri is 22
console.log((3.14159).toFixed(2)); // 3.14  | Python: f"{x:.2f}"

// ----- 8. Char <-> code -----
console.log("A".charCodeAt(0)); // 65   | Python: ord("A")
console.log(String.fromCharCode(66)); // B    | Python: chr(66)

// ----- Quick reference table (TS -> Python) -----
// s.length          -> len(s)
// s.toLowerCase()   -> s.lower()
// s.toUpperCase()   -> s.upper()
// s.indexOf(x)      -> s.find(x)
// s.includes(x)     -> x in s
// s.trim()          -> s.strip()
// s.replaceAll(a,b) -> s.replace(a,b)
// s.split(",")      -> s.split(",")
// arr.join("-")     -> "-".join(arr)
// s.slice(a,b)      -> s[a:b]
