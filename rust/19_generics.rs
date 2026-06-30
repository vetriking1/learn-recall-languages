// ============================================================
// Topic:  Generics
// Summary: fn generic, struct Generic, trait bounds, multiple type params, impl<T>.
// Run:     rustc --edition 2021 rust/19_generics.rs -o rust/19_generics.exe && rust/19_generics.exe
//
// KEY DIFFERENCES:
//   Python:  no compile-time generics; typing.TypeVar at check-time only
//   TS:      generics <T>, extends constraints
//   Rust:    monomorphization — compiler generates concrete copies per type
//   Java:    <T> type parameters, bounded wildcards <? extends T>
//   C++:     templates <typename T>
// ============================================================

// ----- 1. Generic function — one type param -----
fn swap<T>(a: T, b: T) -> (T, T) {
    (b, a) // Python: def swap(a, b): return b, a  (no type enforcement)
}

// ----- 2. Generic struct — holds any type T -----
struct Generic<T> {
    value: T,
}

// ----- 3. Trait bound — T must implement Display for printing -----
fn max<T: Ord>(a: T, b: T) -> T {
    if a > b { a } else { b } // T: Ord = comparable; Python: max(a, b) duck-types
}

// ----- 4. Multiple type parameters -----
struct Pair<A, B> {
    first: A,
    second: B,
}

// ----- 5. impl<T> — methods on generic struct -----
struct Container<T> {
    items: Vec<T>,
}

impl<T> Container<T> {
    fn new() -> Self {
        Container { items: Vec::new() }
    }

    fn push(&mut self, item: T) {
        self.items.push(item);
    }

    fn len(&self) -> usize {
        self.items.len()
    }
}

fn main() {
    // ----- 1. swap — compiler infers T = i32 -----
    let (x, y) = swap(1, 2);
    println!("swap: {} {}", x, y); // Output: swap: 2 1

    // ----- 2. Generic struct with &str -----
    let boxed = Generic { value: "hello" };
    println!("box: {}", boxed.value); // Output: box: hello

    // ----- 3. max with Ord bound -----
    println!("max: {}", max(9, 3)); // Output: max: 9

    // ----- 4. Pair with two different type params -----
    let pair = Pair {
        first: 1,
        second: "two",
    };
    println!("pair: {} {}", pair.first, pair.second); // Output: pair: 1 two

    // ----- 5. impl<T> Container — generic methods -----
    let mut c = Container::new();
    c.push(10);
    c.push(20);
    c.push(30);
    println!("items: {}", c.len()); // Output: items: 3
    // Cross-language: Rust monomorphizes at compile time (zero runtime cost vs Java erasure).
}