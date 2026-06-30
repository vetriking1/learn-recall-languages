// ============================================================
// Topic:  Abstraction  (Rust: a trait IS the abstraction/interface)
// Summary: A trait defines required methods + a default; you can't instantiate it.
// Run:     rustc rust/14_abstraction.rs -o rust/14_abstraction && rust/14_abstraction
// ============================================================

// ----- 1. A trait declares the contract: WHAT, not HOW -----
trait Shape {
    fn area(&self) -> f64;        // required method (no body)
    fn label(&self) -> String;    // required method

    // default method = the concrete, shared part of the contract
    fn describe(&self) -> String {
        format!("{} has area {:.2}", self.label(), self.area())
    }
}

// ----- 2. Each type implements the trait's required methods -----
struct Circle {
    r: i32,
}
impl Shape for Circle {
    fn area(&self) -> f64 { std::f64::consts::PI * (self.r * self.r) as f64 }
    fn label(&self) -> String { format!("Circle with radius {}", self.r) }
}

struct Square {
    s: i32,
}
impl Shape for Square {
    fn area(&self) -> f64 { (self.s * self.s) as f64 }
    fn label(&self) -> String { format!("Square with side {}", self.s) }
}

fn main() {
    // let s = Shape; // ERROR: a trait is not a type you can construct
    println!("{}", Circle { r: 2 }.describe()); // Output: Circle with radius 2 has area 12.57
    println!("{}", Square { s: 3 }.describe()); // Output: Square with side 3 has area 9.00
}

// Cross-language note:
//   Rust has no `abstract class` — a TRAIT is both the interface (required methods)
//   and the place for shared default methods. A trait isn't a concrete type, so you
//   can't instantiate it directly; you implement it for a struct and use that.
