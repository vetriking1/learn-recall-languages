// ============================================================
// Topic:  Strings  (FOCUS: methods & operations)
// Summary: &str vs String, length, case, search, split/join, format.
// Run:     rustc rust/08_strings.rs -o rust/08_strings && rust/08_strings
//
// KEY DIFFERENCE the user cares about:
//   Rust: s.len(), s.to_lowercase()   |   Python: len(s), s.lower()
//   Rust: &str (slice) vs String (owned)
// ============================================================

fn main() {
    let s: &str = "Hello, World";

    // ----- 1. &str vs String -----
    let slice: &str = "hello"; // string slice — borrowed, fixed-size view
    let owned: String = String::from("hello"); // owned, growable
    let also_owned = "hello".to_string(); // another way to create String
    println!("{} {} {}", slice, owned, also_owned); // Output: hello hello hello

    // ----- 2. Length -----
    println!("{}", s.len()); // 12 (byte length)   | Python: len(s)   TS: s.length
    println!("{}", s.chars().count()); // 12 (Unicode scalar count)

    // ----- 3. Indexing (no s[0] — use chars or bytes) -----
    println!("{}", s.chars().next().unwrap()); // H   | Python: s[0]
    println!("{}", s.chars().last().unwrap()); // d   | Python: s[-1]

    // ----- 4. Slicing (byte indices — must be on char boundaries) -----
    println!("{}", &s[0..5]); // Hello
    println!("{}", &s[7..]); // World

    // ----- 5. Case methods -----
    println!("{}", s.to_lowercase()); // hello, world   | Python: s.lower()   TS: toLowerCase()
    println!("{}", s.to_uppercase()); // HELLO, WORLD   | Python: s.upper()   TS: toUpperCase()

    // ----- 6. Search / test -----
    println!("{}", s.find("World").unwrap()); // 7   | Python: s.find()   TS: indexOf()
    println!("{}", s.contains("World")); // true        | Python: "World" in s   TS: includes()
    println!("{}", s.starts_with("Hello")); // true     | TS: startsWith()
    println!("{}", s.ends_with("World")); // true       | TS: endsWith()
    println!("{}", s.matches('l').count()); // 3 (count occurrences)

    // ----- 7. Modify (strings are IMMUTABLE; methods return NEW strings) -----
    println!("{}", s.replace("World", "Vetri")); // Hello, Vetri
    println!("{}", "  pad  ".trim()); // pad         | TS: trim()
    println!("{:?}", "a,b,c".split(',').collect::<Vec<_>>()); // ["a", "b", "c"]
    println!("{}", ["a", "b", "c"].join("-")); // a-b-c   | Python: "-".join(list)
    println!("{}", "ha".repeat(3)); // hahaha         | Python: "ha" * 3

    // ----- 8. Formatting -----
    let name = "Vetri";
    let age = 22;
    println!("{} is {}", name, age); // Vetri is 22   | Python: f"{name} is {age}"
    println!("{}", format!("{} is {}", name, age)); // Vetri is 22 (builds String)

    // ----- 9. Char <-> code -----
    println!("{}", 'A' as u32); // 65   | Python: ord("A")   TS: charCodeAt(0)
    println!("{}", char::from_u32(66).unwrap()); // B   | Python: chr(66)

    // ----- Quick reference table (Rust -> Python/TS) -----
    // s.len()              -> len(s) / s.length
    // s.to_lowercase()     -> s.lower() / s.toLowerCase()
    // s.to_uppercase()     -> s.upper() / s.toUpperCase()
    // s.find(x)            -> s.find(x) / s.indexOf(x)
    // s.contains(x)        -> x in s / s.includes(x)
    // s.trim()             -> s.strip() / s.trim()
    // s.replace(a, b)      -> s.replace(a, b) / s.replaceAll(a, b)
    // s.split(",")         -> s.split(",") / s.split(",")
    // ["a","b"].join("-")  -> "-".join(list) / list.join("-")
    // &s[a..b]             -> s[a:b] / s.slice(a, b)
}