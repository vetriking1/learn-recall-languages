// ============================================================
// Topic:  Modules
// Summary: mod, pub, use, inline submodule, re-export alias, std imports.
// Run:     rustc --edition 2021 rust/20_modules.rs -o rust/20_modules.exe && rust/20_modules.exe
//
// KEY DIFFERENCES:
//   Python:  import / from … import; __init__.py packages
//   TS/JS:   import / export; ES modules vs CommonJS
//   Rust:    mod tree, pub for visibility, use for paths; one crate root (main.rs)
//   Java:    package + import
//   C++:     #include / modules (C++20)
// ============================================================

use std::f64::consts::PI;

// ----- 1. Inline submodule — nested mod with pub fn -----
mod submodule {
    pub fn greet() -> &'static str {
        "Hi" // pub = visible outside this mod; default is private
    }
}

// ----- 2. Inline math_util module -----
mod math_util {
    pub fn sqrt_val(x: f64) -> f64 {
        x.sqrt()
    }

    pub fn square(x: i32) -> i32 {
        x * x
    }
}

// ----- 3. use — bring names into scope -----
use submodule::greet;
use math_util::sqrt_val as sqrt; // alias: sqrt maps to sqrt_val
use math_util::square as alias;  // alias: square imported under another name

fn main() {
    // ----- 1. std constant via use -----
    println!("pi: {:.2}", PI); // Output: pi: 3.14   | Python: from math import pi

    // ----- 2. pub fn from submodule -----
    println!("greet: {}", greet()); // Output: greet: Hi

    // ----- 3. math_util via aliased import -----
    println!("sqrt: {:.1}", sqrt(25.0)); // Output: sqrt: 5.0

    // ----- 4. alias import — square renamed to alias -----
    println!("alias: {}", alias(5)); // Output: alias: 25

    // ----- 5. main module entry point -----
    println!("main module"); // Output: main module
    // Cross-language: Rust modules are a single tree per crate; no separate files required here.
    // In larger projects: mod math_util; → math_util.rs or math_util/mod.rs
}