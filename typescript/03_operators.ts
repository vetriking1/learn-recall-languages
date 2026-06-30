// ============================================================
// Topic:  Operators
// Summary: arithmetic, comparison (== vs ===), logical, increment.
// Run:     npx ts-node typescript/03_operators.ts
// ============================================================

// ----- 1. Arithmetic -----
console.log(5 + 2); // 7
console.log(5 - 2); // 3
console.log(5 * 2); // 10
console.log(5 / 2); // 2.5   (NOT integer; same as Python /)
console.log(Math.floor(5 / 2)); // 2  (floor division; Python: 5 // 2)
console.log(5 % 2); // 1
console.log(5 ** 2); // 25  (power; same as Python)

// ----- 2. Comparison: ALWAYS use === (strict), avoid == (loose) -----
let five = 5,
  three = 3;
console.log(five === 5); // true   strict: value + type   (Python: ==)
console.log(five !== three); // true   (Python: !=)
// To DEMONSTRATE loose `==` we route through `any` — otherwise strict TS refuses
// to even compile a string-vs-number comparison (that strictness is a good thing!).
const looseEq = (a: any, b: any) => a == b;
const strictEq = (a: any, b: any) => a === b;
console.log(looseEq("5", 5)); // true   ⚠ loose: coerces "5" -> 5! avoid ==
console.log(strictEq("5", 5)); // false  strict catches the type mismatch

// ----- 3. Logical (symbols, not words) -----
console.log(true && false); // false  (Python: and)
console.log(true || false); // true   (Python: or)
console.log(!true); // false  (Python: not)

// ----- 4. Increment / decrement (Python has NEITHER) -----
let n = 10;
n++; // 11   (Python: n += 1)
n--; // 10
console.log(n); // Output: 10

// ----- 5. Augmented assignment -----
let m = 10;
m += 5; // 15
m *= 2; // 30
console.log(m); // Output: 30

// ----- 6. Nullish & optional (modern TS niceties) -----
const input = null;
console.log(input ?? "default"); // "default"  (?? uses fallback if null/undefined)
const user = { name: "Vetri" } as { name: string; age?: number };
console.log(user.age?.toString()); // undefined  (?. safe access)

// ----- 7. Membership uses methods, not an operator (Python has `in`) -----
console.log([1, 2, 3].includes(3)); // true   (Python: 3 in [1,2,3])
console.log("cat".includes("a")); // true   (Python: "a" in "cat")

// Cross-language note:
//   Equality: TS `===` (strict) ≈ Python `==`. Avoid TS `==` (it coerces).
//   Increment: TS `i++` exists; Python has no ++ (use i += 1).
