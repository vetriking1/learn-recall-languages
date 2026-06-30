// ============================================================
// Topic:  Conditions
// Summary: if/else, if-as-expression, match, no implicit bool.
// Run:     rustc rust/04_conditions.rs -o rust/04_conditions && rust/04_conditions
// ============================================================

fn main() {
    // ----- 1. Basic if / else if / else -----
    let age = 20;
    if age < 13 {
        println!("child");
    } else if age < 18 {
        println!("teen");
    } else {
        println!("adult");
    }
    // Output: adult

    // ----- 2. if as an expression (returns a value) -----
    // Rust if/else is an expression, not just a statement.
    let status = if age >= 18 { "pass" } else { "fail" };
    println!("{}", status); // Output: pass
    // TS equivalent: const status = age >= 18 ? "pass" : "fail";
    // Python: status = "pass" if age >= 18 else "fail"

    // ----- 3. No implicit bool — condition must be bool -----
    // if 1 { ... }  // ERROR: expected bool, found integer
    // if "hello" { ... }  // ERROR: expected bool, found &str
    let empty = "";
    if empty.is_empty() {
        println!("empty string is empty"); // Output: empty string is empty
    }
    if !"hello".is_empty() {
        println!("non-empty string is not empty"); // Output: non-empty string is not empty
    }

    // ----- 4. Combining conditions -----
    let temp = 25;
    if temp > 20 && temp < 30 {
        println!("comfortable"); // Output: comfortable
    }

    // ----- 5. match — powerful pattern matching -----
    let command = "start";
    match command {
        "start" => println!("starting"), // Output: starting
        "stop" => println!("stopping"),
        _ => println!("unknown"), // default arm (TS: default, Python: case _)
    }

    // ----- 6. match with binding and multiple patterns -----
    let n = 7;
    match n {
        1 | 2 | 3 => println!("small"),
        4..=6 => println!("medium"),
        7..=10 => println!("large"), // Output: large
        _ => println!("out of range"),
    }

    // ----- 7. match as expression -----
    let label = match n {
        1..=3 => "small",
        4..=6 => "medium",
        _ => "large",
    };
    println!("{}", label); // Output: large

    // Cross-language note:
    //   Rust requires explicit bool in if — no truthiness (unlike Python/JS).
    //   `match` is more powerful than TS `switch` — it must be exhaustive.
    //   if/else is an expression that returns a value (like C#'s ternary, but with blocks).
}