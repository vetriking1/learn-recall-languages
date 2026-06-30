// ============================================================
// Topic:  Console Output & Input
// Summary: println!, print!, format!, eprintln!, stdin read_line.
// Run:     rustc rust/06_io.rs -o rust/06_io && rust/06_io
// Note:    This file reads from the keyboard. When piping input use:
//          echo Vetri | rust/06_io
//          (printf "Vetri\n5\n" | rust/06_io  on Unix for both prompts)
// ============================================================

use std::io::{self, Write};

fn main() {
    // ----- 1. Basic output -----
    println!("Hello, world"); // Output: Hello, world

    // ----- 2. Printing multiple values -----
    println!("{} {} {}", "a", "b", "c"); // Output: a b c

    // ----- 3. print! (no newline) and custom formatting -----
    print!("no newline");
    print!("!! ");
    println!("next"); // Output: no newline!! next

    // ----- 4. format! — build a String without printing -----
    let name = "Vetri";
    let age = 22;
    let msg = format!("{} is {}", name, age);
    println!("{}", msg); // Output: Vetri is 22
    println!("{:.2}", 3.14159); // Output: 3.14   (2 decimal places)

    // ----- 5. eprintln! — print to stderr -----
    eprintln!("this goes to stderr"); // Output: this goes to stderr (on stderr stream)

    // ----- 6. Reading input (always returns a String) -----
    print!("Enter your name: ");
    io::stdout().flush().unwrap(); // flush prompt before waiting for input
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let user_name = input.trim(); // trim trailing newline
    println!("Hi {}!", user_name);
    // Example (input "Vetri"):  Hi Vetri!

    // ----- 7. Converting input to a number -----
    print!("Enter a number: ");
    io::stdout().flush().unwrap();
    let mut raw = String::new();
    io::stdin().read_line(&mut raw).unwrap();
    let number: i32 = raw.trim().parse().expect("Please enter a valid number");
    println!("Doubled: {}", number * 2);
    // Example (input "5"):  Doubled: 10

    // Cross-language note:
    //   Rust println!()       == Python print()     == TS console.log()
    //   Rust print!()         == Python print(..., end="")
    //   Rust format!()        == Python f"..."       == TS `${...}` (builds a string)
    //   Rust read_line()      == Python input()      — always returns String; parse for math.
}