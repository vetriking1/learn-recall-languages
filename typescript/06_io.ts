// ============================================================
// Topic:  Console Output & Input
// Summary: console.log variations + reading stdin in Node.
// Run:     npx ts-node typescript/06_io.ts
// Note:    Reads a line from the keyboard. To pipe input:
//          echo "Vetri" | npx ts-node typescript/06_io.ts
// ============================================================

// ----- 1. Basic output -----
console.log("Hello, world"); // Output: Hello, world

// ----- 2. Multiple values (space-separated, like Python print) -----
console.log("a", "b", "c"); // Output: a b c

// ----- 3. Template literals (Python: f-strings) -----
const name = "Vetri";
const age = 22;
console.log(`${name} is ${age}`); // Output: Vetri is 22
console.log((3.14159).toFixed(2)); // Output: 3.14   (Python: f"{x:.2f}")

// ----- 4. Output without a newline -----
process.stdout.write("no newline "); // (Python: print(..., end=""))
console.log("next"); // Output: no newline next

// ----- 5. Other console channels -----
console.error("this goes to stderr"); // for errors
console.warn("a warning"); // warning channel

// ----- 6. Reading input from the keyboard (Node readline) -----
// Python equivalent is the one-liner: input("Enter your name: ")
import * as readline from "readline";

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

rl.question("Enter your name: ", (answer: string) => {
  console.log(`Hi ${answer}!`); // Example (input "Vetri"): Hi Vetri!

  // Reading a number: input is ALWAYS a string — cast it (like Python int()).
  rl.question("Enter a number: ", (raw: string) => {
    const num = Number(raw); // "5" -> 5
    console.log(`Doubled: ${num * 2}`); // Example (input "5"): Doubled: 10
    rl.close();
  });
});

// Cross-language note:
//   console.log()        == Python print()
//   process.stdout.write == Python print(..., end="")
//   readline.question    == Python input()  — and like Python, returns a STRING,
//                           so cast with Number()/parseInt() for math.
//   Big difference: Node input is CALLBACK-based (async); Python input() blocks.
