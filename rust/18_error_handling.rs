// ============================================================
// Topic:  Error Handling
// Summary: Result<T,E>, ? operator, panic!/catch_unwind, custom error enum, match on Err.
// Run:     rustc --edition 2021 rust/18_error_handling.rs -o rust/18_error_handling.exe && rust/18_error_handling.exe
//
// KEY DIFFERENCES:
//   Python:  try/except, raise, finally
//   TS/JS:   try/catch/finally, throw
//   Rust:    Result<T,E> (no exceptions); panic! for unrecoverable; ? propagates Err
//   Java:    try/catch/finally, throws, checked exceptions
//   C++:     try/catch, throw, std::optional / std::expected (C++23)
// ============================================================

// ----- 1. Result<T,E> — Ok/Err instead of throw/catch -----
fn divide(a: i32, b: i32) -> Result<i32, String> {
    if b == 0 {
        Err("division by zero".to_string()) // Python: raise ValueError("division by zero")
    } else {
        Ok(a / b)
    }
}

// ----- 2. Helper prints "caught:" on Err (Python: except block) -----
fn run_with_catch<F>(f: F)
where
    F: FnOnce() -> Result<i32, String>,
{
    match f() {
        Ok(v) => println!("result: {}", v),
        Err(e) => println!("caught: {}", e), // Output: caught: division by zero
    }
}

// ----- 3. finally pattern via Drop (runs when guard goes out of scope) -----
struct Finally;
impl Drop for Finally {
    fn drop(&mut self) {
        println!("finally ran"); // Output: finally ran   | Python: finally block
    }
}

// ----- 4. Custom error enum — match on Err variants -----
#[derive(Debug)]
enum AppError {
    CustomBad(String),
}

fn validate(input: &str) -> Result<(), AppError> {
    if input.is_empty() {
        Err(AppError::CustomBad("invalid".to_string()))
    } else {
        Ok(())
    }
}

// ----- 5. ? operator — propagates Err up the call stack -----
fn inner() -> Result<i32, String> {
    let _ = divide(5, 0)?; // ? returns early with Err if divide fails
    Ok(10)
}

fn outer() -> Result<(), String> {
    match inner() {
        Ok(_) => Ok(()),
        Err(_) => {
            println!("outer: inner failed"); // Output: outer: inner failed
            Err("inner failed".to_string())
        }
    }
}

fn main() {
    // ----- 1. match on Ok — successful Result -----
    match divide(20, 2) {
        Ok(v) => println!("result: {}", v), // Output: result: 10
        Err(e) => println!("caught: {}", e),
    }

    // ----- 2. Helper prints "caught:" on Err -----
    run_with_catch(|| divide(10, 0)); // Output: caught: division by zero

    // ----- 3. Custom error enum — match on Err variant -----
    match validate("") {
        Ok(()) => {}
        Err(AppError::CustomBad(msg)) => println!("CustomBad: {}", msg), // Output: CustomBad: invalid
    }

    // ----- 4. finally via Drop — scoped guard runs cleanup on exit -----
    {
        let _guard = Finally;
    } // Output: finally ran

    // ----- 5. ? propagates from inner; outer handles the failure -----
    let _ = outer(); // Output: outer: inner failed

    // ----- 6. panic!/catch_unwind (optional) — isolate panics without crashing stdout -----
    // panic::catch_unwind(|| panic!("demo")); // catches unwinding panics; no direct Python equivalent
    // Cross-language: Rust prefers Result for recoverable errors; panic! for bugs/invariants.
}