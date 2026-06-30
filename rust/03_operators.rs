// ============================================================
// Topic:  Operators
// Summary: Arithmetic, comparison, logical, assignment operators.
// Run:     rustc rust/03_operators.rs -o rust/03_operators && rust/03_operators
// ============================================================

fn main() {
    // ----- 1. Arithmetic -----
    println!("{}", 5 + 2); // 7
    println!("{}", 5 - 2); // 3
    println!("{}", 5 * 2); // 10
    println!("{}", 5_f64 / 2.0); // 2.5   (int / int truncates: 5/2 == 2)
    println!("{}", 5 / 2); // 2     (integer division; Python: 5//2, TS: Math.floor(5/2))
    println!("{}", 5 % 2); // 1     (modulo)
    println!("{}", 5_i32.pow(2)); // 25    (power; Python: 5**2, no ** in Rust)

    // ----- 2. Comparison (return bool) -----
    println!("{}", 5 == 5); // true   (Rust: == compares values, like Python)
    println!("{}", 5 != 3); // true
    println!("{} {} {} {}", 5 > 3, 5 < 3, 5 >= 5, 5 <= 4); // true false true false

    // ----- 3. Logical -----
    // Rust uses symbols (like TS/C#); Python uses words (and, or, not)
    println!("{}", true && false); // false   (Python: and)
    println!("{}", true || false); // true    (Python: or)
    println!("{}", !true); // false   (Python: not)

    // ----- 4. Chained comparison (not supported — use &&) -----
    let x = 5;
    println!("{}", 1 < x && x < 10); // true   (Python allows: 1 < x < 10)

    // ----- 5. No implicit coercion -----
    let int_val: i32 = 5;
    let float_val: f64 = 2.5;
    // let bad = int_val + float_val;  // ERROR: cannot add i32 and f64
    let good = int_val as f64 + float_val; // explicit cast required
    println!("{}", good); // Output: 7.5

    // ----- 6. Augmented assignment -----
    let mut n = 10;
    n += 5;
    println!("{}", n); // 15
    n -= 3;
    println!("{}", n); // 12
    n *= 2;
    println!("{}", n); // 24
    n /= 5;
    println!("{}", n); // 4
    // Note: Rust has no ++ or -- operators (like Python). Use n += 1.

    // ----- 7. Membership (no `in` operator — use .contains() on collections) -----
    let arr = [1, 2, 3];
    println!("{}", arr.contains(&3)); // true   (Python: 3 in [1,2,3])
    let s = "cat";
    println!("{}", s.contains('a')); // true   (Python: "a" in "cat")

    // Cross-language note:
    //   Equality: Rust `==` compares values (like Python); TS `===` also checks type.
    //   No implicit numeric coercion — cast with `as` or `.into()`.
    //   Power: use `.pow(n)` or `f64::powf()`, not `**`.
    //   Increment: no `i++` — write `i += 1`.
}