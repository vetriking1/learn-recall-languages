// ============================================================
// Practice: Strings
// Summary: manual reverse, palindrome check, char counting.
// Run:     rustc practice/rust/strings.rs -o practice/rust/strings && practice/rust/strings
// ============================================================

// ----- 1. Reverse a string without rev() -----
fn reverse_string(s: &str) -> String {
    let mut result = String::new();
    for ch in s.chars() {
        result.insert(0, ch); // prepend each char
    }
    result
}

// ----- 2. Palindrome check (ignore case and non-alphanumerics) -----
fn is_palindrome(s: &str) -> bool {
    let cleaned: Vec<char> = s
        .chars()
        .filter(|c| c.is_alphanumeric())
        .map(|c| c.to_ascii_lowercase())
        .collect();
    let (mut i, mut j) = (0usize, cleaned.len().wrapping_sub(1));
    while i < j {
        if cleaned[i] != cleaned[j] {
            return false;
        }
        i += 1;
        j -= 1;
    }
    true
}

// ----- 3. Count vowels, consonants, special characters -----
fn count_chars(s: &str) -> (i32, i32, i32) {
    let (mut vowels, mut consonants, mut special) = (0, 0, 0);
    for c in s.chars() {
        let lc = c.to_ascii_lowercase();
        if lc.is_ascii_alphabetic() {
            if "aeiou".contains(lc) {
                vowels += 1;
            } else {
                consonants += 1;
            }
        } else {
            special += 1;
        }
    }
    (vowels, consonants, special)
}

fn main() {
    println!("{}", reverse_string("hello"));                      // Output: olleh
    println!("{}", is_palindrome("A man a plan a canal Panama")); // Output: true
    println!("{}", is_palindrome("hello"));                       // Output: false
    println!("{:?}", count_chars("Hello, World! 123"));           // Output: (3, 7, 7)
}
