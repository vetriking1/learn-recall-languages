// ============================================================
// Topic:  Data Types
// Summary: Scalars, tuples, fixed arrays, type casting.
// Run:     rustc rust/02_datatypes.rs -o rust/02_datatypes && rust/02_datatypes
// ============================================================

fn main() {
    // ----- 1. Core scalar types -----
    let an_int: i32 = 42; // 32-bit signed int   (Python: int, TS: number)
    let a_big_int: i64 = 1_000_000_000; // 64-bit int
    let a_float: f64 = 3.14; // 64-bit float      (Python: float, TS: number)
    let a_str: &str = "hello"; // string slice    (TS: string)
    let a_string = String::from("hello"); // owned, growable string
    let a_bool: bool = true; // bool              (Python: True, note capital T)
    let a_char: char = 'A'; // single Unicode scalar (4 bytes; not a byte!)
    println!(
        "{} {} {} {} {} {} {}",
        an_int, a_big_int, a_float, a_str, a_string, a_bool, a_char
    );
    // Output: 42 1000000000 3.14 hello hello true A

    // ----- 2. Checking / displaying types (compile-time, not runtime) -----
    // Rust types are known at compile time — no typeof at runtime.
    // Use explicit annotations or let the compiler infer.
    let typed: i32 = 42;
    println!("typed i32 value: {}", typed); // Output: typed i32 value: 42

    // ----- 3. Tuple — fixed-size heterogeneous collection -----
    let a_tuple: (i32, f64, &str) = (1, 2.5, "hi");
    println!("{:?}", a_tuple); // Output: (1, 2.5, "hi")
    let (first, second, third) = a_tuple; // destructure
    println!("{} {} {}", first, second, third); // Output: 1 2.5 hi

    // ----- 4. Fixed-size array [T; N] — length known at compile time -----
    let a_array: [i32; 3] = [1, 2, 3]; // immutable, stack-allocated
    let mut a_mut_array = [10, 20, 30];
    a_mut_array[0] = 5;
    println!("{:?} {:?}", a_array, a_mut_array); // Output: [1, 2, 3] [5, 20, 30]

    // ----- 5. Conversion / casting (as keyword) -----
    let n: i32 = 10;
    let doubled = n + 5;
    println!("{}", doubled); // Output: 15

    let from_str: i32 = "10".parse().unwrap(); // str -> int (can fail; returns Result)
    println!("{}", from_str + 5); // Output: 15

    let as_string = 10.to_string(); // int -> String
    println!("{}{}", as_string, "5"); // Output: 105

    let as_float: f64 = 3.5; // from string: "3.5".parse::<f64>().unwrap()
    println!("{}", as_float); // Output: 3.5

    // ----- 6. Numeric details -----
    println!("{}", 7 / 2); // integer division   Output: 3
    println!("{}", 7_f64 / 2.0); // float division   Output: 3.5
    println!("{}", 2_i32.pow(10)); // power (no **)   Output: 1024
    println!("{}", 10 % 3); // modulo              Output: 1

    // ----- 7. Option<T> instead of null -----
    // Rust has no null — use Option::None / Option::Some(value)
    let nothing: Option<i32> = None;
    let something: Option<i32> = Some(42);
    println!("{:?} {:?}", nothing, something); // Output: None Some(42)

    // Cross-language note:
    //   Rust separates i32/i64/f64; Python has int/float; TS/C# have a single number type.
    //   Rust has no null — use Option<T>. Python has None; TS has null/undefined.
    //   [T; N] is a fixed array; growable lists are Vec<T> (see 09_arrays.rs).
}