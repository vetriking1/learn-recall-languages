// ============================================================
// Topic:  Loops
// Summary: C-style for, for..of, for..in, while, entries, array methods.
// Run:     npx ts-node typescript/05_loops.ts
// ============================================================

// ----- 1. Classic C-style for (Python uses range() instead) -----
for (let i = 0; i < 3; i++) {
  process.stdout.write(i + " "); // Output: 0 1 2
}
console.log();

// ----- 2. for..of -> values (Python: for x in coll) -----
const fruits = ["apple", "banana", "cherry"];
for (const fruit of fruits) {
  process.stdout.write(fruit + " "); // Output: apple banana cherry
}
console.log();

// ----- 3. entries() -> index + value (Python: enumerate) -----
for (const [index, fruit] of fruits.entries()) {
  process.stdout.write(`${index}:${fruit} `); // Output: 0:apple 1:banana 2:cherry
}
console.log();

// ----- 4. for..in -> KEYS/indexes (⚠ not values! different from Python) -----
for (const key in fruits) {
  process.stdout.write(key + " "); // Output: 0 1 2  (indexes as strings)
}
console.log();

// ----- 5. while -----
let n = 3;
while (n > 0) {
  process.stdout.write(n + " "); // Output: 3 2 1
  n--;
}
console.log();

// ----- 6. break and continue -----
for (let i = 0; i < 10; i++) {
  if (i === 3) continue; // skip 3
  if (i === 6) break; // stop at 6
  process.stdout.write(i + " "); // Output: 0 1 2 4 5
}
console.log();

// ----- 7. Functional iteration (Python: list comprehension) -----
const squares = [0, 1, 2, 3, 4].map((x) => x * x);
console.log(squares); // Output: [ 0, 1, 4, 9, 16 ]
const evens = [...Array(10).keys()].filter((x) => x % 2 === 0);
console.log(evens); // Output: [ 0, 2, 4, 6, 8 ]

// Cross-language note:
//   TS `for..of` == Python `for x in coll` (values).
//   TS `for..in` gives KEYS — NOT the same as Python's `for x in` (values). Careful!
//   TS replaces range() with the C-style counter loop or [...Array(n).keys()].
