// ============================================================
// Topic:  Variables
// Summary: let / const / var, types, naming, mutability.
// Run:     npx ts-node typescript/01_variables.ts
// ============================================================

// ----- 1. let vs const (prefer const by default) -----
let age = 22; // reassignable        (Python: just age = 22)
const name = "Vetri"; // cannot be reassigned
console.log(name, age); // Output: Vetri 22

age = 23; // OK, let is mutable
console.log(age); // Output: 23
// name = "X";  // ❌ ERROR: const cannot be reassigned (Python has no real const)

// ----- 2. Type annotations (TS's whole point; Python's are optional) -----
let username: string = "abc";
let count: number = 5;
let active: boolean = true;
console.log(username, count, active); // Output: abc 5 true

// ----- 3. Type inference (TS guesses the type, so annotations are often optional) -----
let score = 10; // inferred as number
// score = "ten"; // ❌ ERROR: not assignable to number (Python WOULD allow this)
console.log(score); // Output: 10

// ----- 4. Multiple declaration & swap -----
let x = 1,
  y = 2;
[x, y] = [y, x]; // destructuring swap   (Python: x, y = y, x)
console.log(x, y); // Output: 2 1

// ----- 5. Naming: camelCase is the TS convention (Python uses snake_case) -----
const totalPrice = 99.5;
console.log(totalPrice); // Output: 99.5

// ----- 6. var (legacy, avoid) -----
var old = "don't use me"; // function-scoped, leaks; use let/const
console.log(old); // Output: don't use me

// Cross-language note:
//   TS:     const name = "Vetri";  // or let
//   Python: name = "Vetri"         // no keyword, no real const
