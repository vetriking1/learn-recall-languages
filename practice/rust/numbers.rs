// ============================================================
// Practice: Numbers
// Summary: prime check, multiplication table, Euclidean GCD.
// Run:     rustc practice/rust/numbers.rs -o practice/rust/numbers && practice/rust/numbers
// ============================================================

// ----- 1. Is a number prime? -----
fn is_prime(n: i64) -> bool {
    if n < 2 {
        return false;
    }
    let mut i = 2i64;
    while i * i <= n {
        if n % i == 0 {
            return false;
        }
        i += 1;
    }
    true
}

// ----- 2. Multiplication table for n, 1..=limit -----
fn print_table(n: i32, limit: i32) {
    for i in 1..=limit {
        println!("{} x {} = {}", n, i, n * i);
    }
}

// ----- 3. GCD via the Euclidean algorithm -----
fn gcd(mut a: i32, mut b: i32) -> i32 {
    while b != 0 {
        let t = b;
        b = a % b;
        a = t;
    }
    a
}

fn main() {
    println!("{} {}", is_prime(7), is_prime(10)); // Output: true false
    print_table(7, 10);                            // 7 x 1 = 7 ... 7 x 10 = 70
    println!("{}", gcd(48, 18));                   // Output: 6
}
