// ============================================================
// Topic:  Functions
// Summary: fn, return types, implicit return, closures, Option<T>.
// Run:     rustc rust/07_functions.rs -o rust/07_functions && rust/07_functions
// ============================================================

// ----- 1. Basic function -----
fn greet(name: &str) -> String {
    format!("Hello, {}", name)
}

// ----- 2. Type annotations (mandatory in Rust) -----
fn add(a: i32, b: i32) -> i32 {
    return a + b; // explicit return
}

// ----- 3. Implicit return (no semicolon on last expression) -----
fn multiply(a: i32, b: i32) -> i32 {
    a * b // no semicolon = returned value
}

// ----- 4. Default parameters — Rust has no defaults; use multiple fns or Option -----
fn power(base: i32, exp: i32) -> i32 {
    base.pow(exp as u32)
}

// ----- 5. Returning multiple values via tuple -----
fn min_max(nums: &[i32]) -> (i32, i32) {
    let mut min = nums[0];
    let mut max = nums[0];
    for &n in nums {
        if n < min {
            min = n;
        }
        if n > max {
            max = n;
        }
    }
    (min, max)
}

// ----- 6. Option<T> — safe alternative to null -----
fn safe_div(a: i32, b: i32) -> Option<i32> {
    if b == 0 {
        None
    } else {
        Some(a / b)
    }
}

fn main() {
    println!("{}", greet("Vetri")); // Output: Hello, Vetri

    println!("{}", add(2, 3)); // Output: 5

    println!("{}", multiply(4, 5)); // Output: 20

    println!("{}", power(5, 2)); // Output: 25
    println!("{}", power(5, 3)); // Output: 125

    let (low, high) = min_max(&[4, 1, 9, 2]);
    println!("{} {}", low, high); // Output: 1 9

    println!("{:?}", safe_div(10, 2)); // Output: Some(5)
    println!("{:?}", safe_div(10, 0)); // Output: None

    // ----- 7. Closures (anonymous functions) -----
    let square = |x: i32| x * x;
    println!("{}", square(6)); // Output: 36

    // Closure as callback (sort by descending)
    let mut nums = vec![3, 1, 2];
    nums.sort_by(|a, b| b.cmp(a));
    println!("{:?}", nums); // Output: [3, 2, 1]

    // ----- 8. Higher-order function -----
    fn apply(f: fn(i32) -> i32, x: i32) -> i32 {
        f(x)
    }
    fn double(n: i32) -> i32 {
        n * 2
    }
    println!("{}", apply(double, 7)); // Output: 14

    // Cross-language note:
    //   Rust `fn f(x) -> T { ... }`  == Python `def f(x):`  == TS `function f(x): T`
    //   Rust closures `|x| x*x`     == Python `lambda x: x*x`  == TS `(x) => x*x`
    //   Rust returns tuples for multiple values; Python/TS use tuples/arrays/objects.
    //   Rust has no default params — use builder patterns or Option arguments instead.
    //   Option<T> replaces null: Some(value) or None.
}