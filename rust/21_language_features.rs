// ============================================================
// Topic:  Language Features  (FOCUS: Rust-only idioms)
// Summary: Ownership move, borrow &str, exhaustive match, Option, trait+impl, slice.
// Run:     rustc --edition 2021 rust/21_language_features.rs -o rust/21_language_features.exe && rust/21_language_features.exe
//
// KEY DIFFERENCES:
//   Python:  GC references; no move/borrow; match (3.10+); Optional typing only
//   TS/JS:   GC references; no ownership; switch; null/undefined
//   Rust:    move semantics, borrow checker, match, Option<T>, traits, slices
//   Java:    GC; no ownership; switch; Optional wrapper
//   C++:     move semantics (C++11); references; switch; std::optional
// ============================================================

// ----- 1. Ownership move — value transferred; original binding invalid -----
fn take_ownership(s: String) -> String {
    s // Python: references shared; Rust: ownership moves into this function
}

// ----- 2. Borrow &str — read-only reference, no move -----
fn borrow_str(s: &str) -> &str {
    s // &str = borrowed view; caller keeps ownership of the String
}

// ----- 3. Enum for exhaustive match — compiler requires all variants -----
#[allow(dead_code)] // One/Three needed for exhaustive arms; demo uses Two only
enum Count {
    One,
    Two,
    Three,
}

fn label_count(c: Count) -> &'static str {
    match c {
        Count::One => "one",
        Count::Two => "two",
        Count::Three => "three", // missing arm = compile error (exhaustive)
    }
}

// ----- 4. Option — Some/None instead of null -----
fn maybe_value() -> Option<i32> {
    Some(42) // Option<T> = explicit absent/present; Python: Optional[int] hint only
}

// ----- 5. Trait + impl — shared behavior without inheritance -----
trait Double {
    fn double(&self) -> i32;
}

struct Six(i32);

impl Double for Six {
    fn double(&self) -> i32 {
        self.0 * 2 // trait = interface-like contract; impl = method block
    }
}

// ----- 6. Slice &[i32] — fat pointer view into contiguous memory -----
fn slice_middle(data: &[i32]) -> &[i32] {
    &data[1..3] // slice = pointer + length; no copy of elements
}

fn main() {
    // ----- 1. Ownership move -----
    let owned = String::from("owned");
    let moved = take_ownership(owned);
    // owned is invalid here after move — borrow checker enforces single owner
    println!("move: {}", moved); // Output: move: owned

    // ----- 2. Borrow &str -----
    let msg = String::from("hello");
    let borrowed = borrow_str(&msg);
    println!("borrow: {}", borrowed); // Output: borrow: hello
    // msg still valid — we only borrowed, did not move

    // ----- 3. match exhaustive -----
    let c = Count::Two;
    println!("match: {}", label_count(c)); // Output: match: two

    // ----- 4. Option Some/None -----
    match maybe_value() {
        Some(n) => println!("option: {}", n), // Output: option: 42
        None => println!("option: none"),
    }

    // ----- 5. Trait + impl -----
    let val = Six(6);
    println!("trait: {}", val.double()); // Output: trait: 12

    // ----- 6. Slice &[i32] -----
    let arr = [1, 2, 3, 4];
    let mid = slice_middle(&arr);
    println!("slice: {} {}", mid[0], mid[1]); // Output: slice: 2 3
    // Cross-language note:
    //   move/borrow  == Python GC shares refs; C++ move transfers; Rust enforces at compile time.
    //   &str/&[T]    == borrowed views; Python slices copy references; C++ string_view/span similar.
    //   match        == Python match/case; Java switch; must cover every enum variant in Rust.
    //   Option<T>    == Java Optional; TS null/undefined; Rust forces explicit Some/None handling.
    //   trait+impl   == Java interface + class; no inheritance hierarchy required in Rust.
}