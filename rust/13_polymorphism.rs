// ============================================================
// Topic:  Polymorphism  (Rust: trait objects — Box<dyn Trait>)
// Summary: Store different types behind one trait; calls dispatch dynamically.
// Run:     rustc rust/13_polymorphism.rs -o rust/13_polymorphism && rust/13_polymorphism
// ============================================================

trait Shape {
    fn name(&self) -> String;
    fn area(&self) -> f64;
}

struct Circle {
    r: f64,
}
impl Shape for Circle {
    fn name(&self) -> String { "Circle".to_string() }
    fn area(&self) -> f64 { std::f64::consts::PI * self.r * self.r }
}

struct Rectangle {
    w: f64,
    h: f64,
}
impl Shape for Rectangle {
    fn name(&self) -> String { "Rectangle".to_string() }
    fn area(&self) -> f64 { self.w * self.h }
}

fn main() {
    // Box<dyn Shape> = a "trait object": different concrete types, one interface.
    let shapes: Vec<Box<dyn Shape>> = vec![
        Box::new(Circle { r: 2.0 }),
        Box::new(Rectangle { w: 3.0, h: 4.0 }),
    ];

    let mut total = 0.0;
    for s in &shapes {
        println!("{} area: {:.2}", s.name(), s.area());
        total += s.area();
    }
    println!("Total area: {:.2}", total);
    // Output:
    // Circle area: 12.57
    // Rectangle area: 12.00
    // Total area: 24.57
}

// Cross-language note:
//   Rust has two flavors of polymorphism:
//     - STATIC (generics / `impl Trait`) — resolved at compile time, no runtime cost.
//     - DYNAMIC (`dyn Trait` behind a pointer like Box) — resolved at runtime via a
//       vtable, which is what lets a Vec hold a mix of Circle and Rectangle here.
