// ============================================================
// Topic:  Conditions
// Summary: if / else if / else, ternary, truthiness, switch.
// Run:     npx ts-node typescript/04_conditions.ts
// ============================================================

// ----- 1. Basic if / else if / else (needs ( ) around test and { } block) -----
const age = 20;
if (age < 13) {
  console.log("child");
} else if (age < 18) {
  // Python: elif
  console.log("teen");
} else {
  console.log("adult");
}
// Output: adult

// ----- 2. Ternary (cond ? a : b) -----
const status = age >= 18 ? "pass" : "fail";
console.log(status); // Output: pass
// Python: status = "pass" if age >= 18 else "fail"   (word order reversed)

// ----- 3. Truthiness -----
// Falsy in TS: false, 0, "", null, undefined, NaN
// ⚠ DIFFERENCE: empty array [] and empty object {} are TRUTHY in TS,
//   but [] and {} are FALSY in Python!
const emptyArr: unknown[] = [];
if (!emptyArr) {
  console.log("never prints"); // [] is truthy in TS
} else {
  console.log("empty array is TRUTHY in TS"); // Output: this line
}
const greeting = "hello";
if (greeting) console.log("non-empty string is truthy"); // Output: ...truthy

// ----- 4. Combining conditions -----
const temp = 25;
if (temp > 20 && temp < 30) {
  console.log("comfortable"); // Output: comfortable
}

// ----- 5. switch (Python: match/case) -----
const command: string = "start";
switch (command) {
  case "start":
    console.log("starting"); // Output: starting
    break; // ⚠ don't forget break (Python match has no fall-through)
  case "stop":
    console.log("stopping");
    break;
  default:
    console.log("unknown");
}

// Cross-language note:
//   TS needs ( ) around the condition and { } for the block; Python uses indentation.
//   Ternary order: TS `cond ? a : b`  vs  Python `a if cond else b`.
//   [] and {} are TRUTHY in TS but FALSY in Python — easy bug source.
