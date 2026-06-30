// ============================================================
// Topic:  Inheritance  (Rust has NONE — reuse via traits + composition)
// Summary: A trait with a default method gives shared behavior; types override it.
// Run:     rustc rust/12_inheritance.rs -o rust/12_inheritance && rust/12_inheritance
// ============================================================

// Rust deliberately has no class inheritance. The idiomatic replacements are:
//   - a TRAIT with default methods   -> shared behavior (what a base class gives you)
//   - COMPOSITION (structs holding other structs) -> "is built from", not "is a"

trait Animal {
    fn name(&self) -> &str;                       // required (like an abstract getter)
    fn sound(&self) -> String {                   // default impl = shared behavior
        "some sound".to_string()
    }
    fn describe(&self) -> String {                // default uses the other methods
        format!("{} says {}", self.name(), self.sound())
    }
}

struct GenericAnimal {
    name: String,
}
impl Animal for GenericAnimal {
    fn name(&self) -> &str { &self.name }         // takes both defaults as-is
}

struct Dog {
    name: String,
    breed: String,
}
impl Animal for Dog {
    fn name(&self) -> &str { &self.name }
    fn sound(&self) -> String { "Woof".to_string() }      // override the default
    fn describe(&self) -> String {                         // extend (no `super`)
        format!("{} says {} ({})", self.name, self.sound(), self.breed)
    }
}

struct Cat {
    name: String,
}
impl Animal for Cat {
    fn name(&self) -> &str { &self.name }
    fn sound(&self) -> String { "Meow".to_string() }       // override only sound
}

fn main() {
    let a = GenericAnimal { name: "Creature".to_string() };
    let d = Dog { name: "Rex".to_string(), breed: "Labrador".to_string() };
    let c = Cat { name: "Whiskers".to_string() };
    println!("{}", a.describe()); // Output: Creature says some sound
    println!("{}", d.describe()); // Output: Rex says Woof (Labrador)
    println!("{}", c.describe()); // Output: Whiskers says Meow
}

// Cross-language note:
//   No `extends`, no base class, no `super`. A trait's DEFAULT methods play the role of
//   inherited behavior; each type re-implements only what differs. To reuse *data*, a
//   struct embeds another struct (composition) rather than inheriting fields.
