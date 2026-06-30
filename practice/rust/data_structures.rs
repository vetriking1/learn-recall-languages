// ============================================================
// Practice: Data Structures
// Summary: word frequency, two-sum, dedupe, parens, merge, anagrams.
// Run:     rustc practice/rust/data_structures.rs -o practice/rust/data_structures && practice/rust/data_structures
// ============================================================

use std::collections::HashMap;

// ----- 1. Word frequency in a sentence -----
fn word_frequency(text: &str) -> HashMap<String, i32> {
    let mut counts = HashMap::new();
    for word in text.split_whitespace() {
        *counts.entry(word.to_string()).or_insert(0) += 1;
    }
    counts
}

fn print_word_frequency(text: &str, map: &HashMap<String, i32>) {
    let mut order: Vec<&str> = Vec::new();
    for word in text.split_whitespace() {
        if !order.contains(&word) {
            order.push(word);
        }
    }
    print!("{{");
    for (i, key) in order.iter().enumerate() {
        if i > 0 {
            print!(", ");
        }
        print!("'{}': {}", key, map[*key]);
    }
    println!("}}");
}

// ----- 2. Two-sum: indices of pair that adds to target -----
fn two_sum(nums: &[i32], target: i32) -> Vec<usize> {
    let mut seen = HashMap::new();
    for (i, &num) in nums.iter().enumerate() {
        let need = target - num;
        if let Some(&j) = seen.get(&need) {
            return vec![j, i];
        }
        seen.insert(num, i);
    }
    vec![]
}

// ----- 3. Remove duplicates, preserve first-seen order -----
fn remove_duplicates_preserve_order(arr: &[i32]) -> Vec<i32> {
    let mut seen = std::collections::HashSet::new();
    let mut result = Vec::new();
    for &x in arr {
        if seen.insert(x) {
            result.push(x);
        }
    }
    result
}

// ----- 4. Valid parentheses (stack) -----
fn valid_parentheses(s: &str) -> bool {
    let mut stack: Vec<char> = Vec::new();
    for ch in s.chars() {
        match ch {
            '(' | '[' | '{' => stack.push(ch),
            ')' => {
                if stack.pop() != Some('(') {
                    return false;
                }
            }
            ']' => {
                if stack.pop() != Some('[') {
                    return false;
                }
            }
            '}' => {
                if stack.pop() != Some('{') {
                    return false;
                }
            }
            _ => {}
        }
    }
    stack.is_empty()
}

// ----- 5. Merge two sorted slices -----
fn merge_two_sorted(a: &[i32], b: &[i32]) -> Vec<i32> {
    let (mut i, mut j) = (0, 0);
    let mut result = Vec::new();
    while i < a.len() && j < b.len() {
        if a[i] <= b[j] {
            result.push(a[i]);
            i += 1;
        } else {
            result.push(b[j]);
            j += 1;
        }
    }
    result.extend_from_slice(&a[i..]);
    result.extend_from_slice(&b[j..]);
    result
}

// ----- 6. Group anagrams -----
fn group_anagrams(words: &[&str]) -> Vec<Vec<String>> {
    let mut groups: HashMap<String, Vec<String>> = HashMap::new();
    for word in words {
        let mut key: Vec<char> = word.chars().collect();
        key.sort_unstable();
        let key: String = key.into_iter().collect();
        groups.entry(key).or_default().push(word.to_string());
    }
    let mut result: Vec<Vec<String>> = groups.into_values().collect();
    for group in &mut result {
        group.sort();
    }
    result.sort_by(|a, b| a[0].cmp(&b[0]));
    result
}

fn print_py_nested_list(groups: &[Vec<String>]) {
    print!("[");
    for (gi, group) in groups.iter().enumerate() {
        if gi > 0 {
            print!(", ");
        }
        print!("[");
        for (wi, word) in group.iter().enumerate() {
            if wi > 0 {
                print!(", ");
            }
            print!("'{}'", word);
        }
        print!("]");
    }
    println!("]");
}

fn main() {
    let text = "the cat sat on the mat cat";
    let freq = word_frequency(text);
    print_word_frequency(text, &freq); // Output: {'the': 2, 'cat': 2, 'sat': 1, 'on': 1, 'mat': 1}

    println!("{:?}", two_sum(&[2, 7, 11, 15], 9)); // Output: [0, 1]

    println!(
        "{:?}",
        remove_duplicates_preserve_order(&[1, 2, 2, 3, 1, 4, 3])
    ); // Output: [1, 2, 3, 4]

    println!("{}", valid_parentheses("()[]{}")); // Output: true
    println!("{}", valid_parentheses("(]")); // Output: false

    println!("{:?}", merge_two_sorted(&[1, 3, 4, 7], &[2, 6])); // [1, 2, 3, 4, 6, 7]

    print_py_nested_list(&group_anagrams(&["eat", "tea", "tan", "ate", "nat", "bat"]));
    // Output: [['ate', 'eat', 'tea'], ['bat'], ['nat', 'tan']]
}