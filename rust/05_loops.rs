// ============================================================
// Topic:  Loops
// Summary: loop, while, for, ranges, enumerate, break/continue.
// Run:     rustc rust/05_loops.rs -o rust/05_loops && rust/05_loops
// ============================================================

fn main() {
    // ----- 1. for over a range -----
    // 0..3 means 0, 1, 2 (exclusive end)   |  Python: range(3)   TS: for (let i=0; i<3; i++)
    print!("range 0..3: ");
    for i in 0..3 {
        print!("{} ", i); // Output: 0 1 2
    }
    println!();

    // range with step: (2..11).step_by(2)
    print!("range 2..11 step 2: ");
    for i in (2..11).step_by(2) {
        print!("{} ", i); // Output: 2 4 6 8 10
    }
    println!();

    // ----- 2. for over a collection (for..in) -----
    let fruits = ["apple", "banana", "cherry"];
    print!("fruits: ");
    for fruit in fruits.iter() {
        print!("{} ", fruit); // Output: apple banana cherry
    }
    println!();

    // ----- 3. enumerate -> index + value -----
    print!("enumerate: ");
    for (index, fruit) in fruits.iter().enumerate() {
        print!("{}:{} ", index, fruit); // Output: 0:apple 1:banana 2:cherry
    }
    println!();

    // ----- 4. while loop -----
    let mut n = 3;
    print!("while: ");
    while n > 0 {
        print!("{} ", n); // Output: 3 2 1
        n -= 1;
    }
    println!();

    // ----- 5. loop (infinite until break) with break value -----
    let mut counter = 0;
    let result = loop {
        counter += 1;
        if counter == 10 {
            break counter * 2; // break can return a value from loop
        }
    };
    println!("loop break value: {}", result); // Output: loop break value: 20

    // ----- 6. break and continue -----
    print!("break/continue: ");
    for i in 0..10 {
        if i == 3 {
            continue; // skip 3
        }
        if i == 6 {
            break; // stop at 6
        }
        print!("{} ", i); // Output: 0 1 2 4 5
    }
    println!();

    // ----- 7. Iterator methods (like Python comprehensions / TS map/filter) -----
    let squares: Vec<i32> = (0..5).map(|x| x * x).collect();
    println!("{:?}", squares); // Output: [0, 1, 4, 9, 16]

    let evens: Vec<i32> = (0..10).filter(|x| x % 2 == 0).collect();
    println!("{:?}", evens); // Output: [0, 2, 4, 6, 8]

    // Cross-language note:
    //   Rust `for x in coll` == Python `for x in coll` == TS `for (const x of coll)`.
    //   `0..n` is exclusive end; use `0..=n` for inclusive.
    //   `loop { }` has no direct Python equivalent; `while` and `for` are familiar.
    //   Only `loop` (not while/for) can `break` with a value.
}