// ============================================================
// Practice: Patterns
// Summary: right-angled triangle, centered pyramid.
// Run:     rustc practice/rust/patterns.rs -o practice/rust/patterns && practice/rust/patterns
// ============================================================

// ----- 1. Right-angled triangle of stars -----
fn right_triangle(n: usize) {
    for i in 1..=n {
        println!("{}", "*".repeat(i));
    }
}

// ----- 2. Centered pyramid of stars (height h) -----
fn pyramid(h: usize) {
    for i in 1..=h {
        let spaces = " ".repeat(h - i);
        let stars = "*".repeat(2 * i - 1);
        println!("{}{}", spaces, stars);
    }
}

fn main() {
    println!("Right triangle (N=5):");
    right_triangle(5);
    // *
    // **
    // ***
    // ****
    // *****

    println!("Pyramid (height=5):");
    pyramid(5);
    //     *
    //    ***
    //   *****
    //  *******
    // *********
}
