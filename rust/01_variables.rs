// ============================================================
// Topic:  Variables
// Summary: let, mut, const, shadowing, type inference, snake_case.
// Run:     rustc rust/01_variables.rs -o rust/01_variables && rust/01_variables
// ============================================================

fn main() {
    // ----- 1. Basic declaration (let — immutable by default) -----
    let name = "Vetri"; // type inferred as &str   (Python: name = "Vetri")
    let age: i32 = 22;  // explicit type annotation (TS: let age: number = 22)
    println!("{} {}", name, age); // Output: Vetri 22

    // ----- 2. mut — make a binding mutable -----
    let mut score = 10;
    println!("{}", score); // Output: 10
    score = 20; // OK with mut   (without mut this would not compile)
    println!("{}", score); // Output: 20

    // ----- 3. const — compile-time constant -----
    const PI: f64 = 3.14159; // must have a type; cannot reassign
    println!("{}", PI); // Output: 3.14159
    // PI = 3.0;  // ERROR: cannot assign to const

    // ----- 4. Shadowing — reuse the name, new binding -----
    let x = 5;
    let x = x + 1; // shadows previous x (can even change type)
    let x = x * 2;
    println!("{}", x); // Output: 12

    // ----- 5. Multiple assignment via tuples -----
    let (x, y, z) = (1, 2, 3);
    let (a, b, c) = (0, 0, 0);
    println!("{} {} {} {} {} {}", x, y, z, a, b, c); // Output: 1 2 3 0 0 0

    // ----- 6. Swapping via tuple destructure -----
    let (mut x, mut y) = (1, 2);
    (x, y) = (y, x); // (Python: x, y = y, x)
    println!("{} {}", x, y); // Output: 2 1

    // ----- 7. Type inference -----
    let inferred = 42; // i32 by default for integer literals
    let also_float = 3.14; // f64 by default for float literals
    println!("{} {}", inferred, also_float); // Output: 42 3.14

    // ----- 8. Naming: snake_case convention -----
    let total_price = 99.5; // good   (TS/C# use camelCase: totalPrice)
    println!("{}", total_price); // Output: 99.5

    // ----- 9. Static typing (no silent type change on rebind) -----
    let thing: i32 = 5;
    // thing = "text";  // ERROR: expected i32, found &str
    println!("{}", thing); // Output: 5

    // Cross-language note:
    //   Rust:    let name = "Vetri";  let mut score = 10;  const PI: f64 = 3.14;
    //   TS:      let name = "Vetri";  const PI = 3.14;
    //   Python:  name = "Vetri"      (no let/const; everything is a rebind)
    //   C#:      var name = "Vetri"; const double PI = 3.14;
    //   Rust `let` is immutable unless `mut`; shadowing lets you "redeclare" with a new value/type.
}