// ============================================================
// Topic:  Functions
// Summary: function, arrow functions, defaults, rest, return.
// Run:     npx ts-node typescript/07_functions.ts
// ============================================================

// ----- 1. Basic function (typed params + return) -----
function greet(name: string): string {
  return `Hello, ${name}`;
}
console.log(greet("Vetri")); // Output: Hello, Vetri

// ----- 2. Arrow function (Python: lambda, but arrows can be full-bodied) -----
const add = (a: number, b: number): number => a + b;
console.log(add(2, 3)); // Output: 5

// ----- 3. Default parameters -----
function power(base: number, exp: number = 2): number {
  return base ** exp;
}
console.log(power(5)); // Output: 25
console.log(power(5, 3)); // Output: 125

// ----- 4. Optional parameters (the ? — Python uses =None defaults) -----
function makeUser(name: string, age?: number): string {
  return `${name}/${age ?? "unknown"}`;
}
console.log(makeUser("Vetri")); // Output: Vetri/unknown
console.log(makeUser("Vetri", 22)); // Output: Vetri/22

// ----- 5. Rest parameters (Python: *args) -----
function total(...numbers: number[]): number {
  return numbers.reduce((a, b) => a + b, 0);
}
console.log(total(1, 2, 3, 4)); // Output: 10

// ----- 6. "Multiple returns" via array or object (Python: tuple) -----
function minMax(nums: number[]): [number, number] {
  return [Math.min(...nums), Math.max(...nums)];
}
const [low, high] = minMax([4, 1, 9, 2]);
console.log(low, high); // Output: 1 9

// ----- 7. Functions as values / callbacks -----
const nums = [3, 1, 2];
console.log([...nums].sort((a, b) => b - a)); // Output: [ 3, 2, 1 ]

// Cross-language note:
//   TS `function f(x) {}`   == Python `def f(x):`
//   TS `(x) => x*x`         == Python `lambda x: x*x`
//   TS returns tuple-array `[a,b]`; Python returns a real tuple `a, b`.
//   Params are typed in TS (a: number) — Python's hints are optional.
