// ============================================================
// Topic:  Data Types
// Summary: primitives, typeof, null vs undefined, casting.
// Run:     npx ts-node typescript/02_datatypes.ts
// ============================================================

// ----- 1. Primitive types (note: ONE number type, no int/float split) -----
let n: number = 42; // also 3.14 — number covers both (Python: int AND float)
let str: string = "hello"; // Python: str
let flag: boolean = true; // Python: True/False (lowercase here!)
let nothing: null = null; // Python: None
let missing: undefined = undefined; // Python has NO equivalent (only None)
console.log(n, str, flag, nothing, missing);
// Output: 42 hello true null undefined

// ----- 2. Checking a type -> typeof  (Python: type(x)) -----
console.log(typeof n); // Output: number
console.log(typeof str); // Output: string
console.log(typeof flag); // Output: boolean
console.log(typeof undefined); // Output: undefined

// ----- 3. Collection types -----
const arr: number[] = [1, 2, 3]; // array        (Python: list)
const obj = { k: "v" }; // object       (Python: dict)
const map = new Map([["k", "v"]]); // Map          (Python: dict)
const set = new Set([1, 2, 3]); // Set          (Python: set)
console.log(arr, obj, map, set);

// ----- 4. Conversion / casting -----
console.log(Number("10") + 5); // 15    | Python: int("10") + 5
console.log(String(10) + "5"); // "105" | Python: str(10) + "5"
console.log(parseInt("3.9")); // 3     (parse to int)
console.log(parseFloat("3.5")); // 3.5
console.log(Boolean(0), Boolean(""), Boolean(1)); // false false true

// ----- 5. The two "empty" values (Python only has None) -----
let a; // undefined: declared but never assigned
let b = null; // null: intentionally empty
console.log(a, b); // Output: undefined null

// ----- 6. Special TS types -----
let anything: any = 5; // disables checking (avoid)
anything = "now a string"; // allowed with any
let unknownVal: unknown = 10; // safer "any"; must narrow before use
console.log(anything, unknownVal); // Output: now a string 10

// Cross-language note:
//   TS has ONE `number` (a 64-bit float). Python splits int vs float.
//   TS has TWO empties: null + undefined. Python has just None.
