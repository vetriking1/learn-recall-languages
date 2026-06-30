// ============================================================
// Topic:  Classes & Objects  (Rust has no `class` — use struct + impl)
// Summary: A struct holds state; an impl block holds behavior (methods).
// Run:     rustc rust/10_classes.rs -o rust/10_classes && rust/10_classes
// ============================================================

// ----- 1. A struct holds the data (the "fields") -----
struct Person {
    name: String,
    age: u32,
}

// ----- 2. An impl block holds the methods (the "behavior") -----
impl Person {
    // Associated function used as a constructor (convention: `new`).
    // No `self` -> called as Person::new(...).
    fn new(name: &str, age: u32) -> Person {
        Person {
            name: name.to_string(),
            age,
        }
    }

    // Instance method: &self borrows the instance immutably.
    fn greet(&self) -> String {
        format!("Hi, I'm {} and I'm {}", self.name, self.age)
    }

    // Mutating method: &mut self borrows it mutably.
    fn birthday(&mut self) {
        self.age += 1;
    }
}

fn main() {
    // ----- 3. Create instances; no `new` keyword — call the constructor fn -----
    let p1_immutable = Person::new("Asha", 30);
    let mut p1 = Person::new("Vetri", 22); // `mut` needed to call birthday()
    println!("{}", p1.greet());            // Output: Hi, I'm Vetri and I'm 22
    println!("{}", p1_immutable.greet());  // Output: Hi, I'm Asha and I'm 30

    p1.birthday();                          // mutate state (requires `mut`)
    println!("{}", p1.greet());            // Output: Hi, I'm Vetri and I'm 23
}

// Cross-language note:
//   Rust has NO classes. Data lives in a `struct`; methods live in `impl`.
//   There's no built-in constructor — convention is an associated fn `new`.
//   Methods take an explicit receiver: &self (read), &mut self (mutate), self (consume).
//   Mutability is on the binding (`let mut`), not the type. See 12_inheritance: Rust
//   has no inheritance either — it composes structs and shares behavior via traits.
