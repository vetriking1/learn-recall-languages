// ============================================================
// Practice: Algorithms
// Summary: linear search, binary search, Fibonacci (iter + rec).
// Run:     rustc practice/rust/algorithms.rs -o practice/rust/algorithms && practice/rust/algorithms
// ============================================================

// ----- 1. Linear search -> index, or -1 if not found -----
fn linear_search(arr: &[i32], target: i32) -> i32 {
    for (i, &x) in arr.iter().enumerate() {
        if x == target {
            return i as i32;
        }
    }
    -1
}

// ----- 2. Binary search on a SORTED slice -> index, or -1 -----
fn binary_search(arr: &[i32], target: i32) -> i32 {
    let (mut lo, mut hi) = (0i32, arr.len() as i32 - 1);
    while lo <= hi {
        let mid = (lo + hi) / 2;
        let val = arr[mid as usize];
        if val == target {
            return mid;
        } else if val < target {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    -1
}

// ----- 3a. Fibonacci, iterative (N terms) -----
fn fib_iterative(n: usize) -> Vec<u64> {
    let mut seq = Vec::new();
    let (mut a, mut b) = (0u64, 1u64);
    for _ in 0..n {
        seq.push(a);
        let next = a + b;
        a = b;
        b = next;
    }
    seq
}

// ----- 3b. Fibonacci, recursive (nth term) -----
fn fib_recursive(n: u64) -> u64 {
    if n < 2 {
        return n;
    }
    fib_recursive(n - 1) + fib_recursive(n - 2)
}

fn main() {
    println!("{}", linear_search(&[4, 2, 7, 1, 9, 3], 7));   // Output: 2
    println!("{}", linear_search(&[4, 2, 7, 1, 9, 3], 5));   // Output: -1
    println!("{}", binary_search(&[1, 3, 5, 7, 9, 11], 7));  // Output: 3
    println!("{}", binary_search(&[1, 3, 5, 7, 9, 11], 4));  // Output: -1
    println!("{:?}", fib_iterative(10));                      // [0, 1, 1, 2, 3, 5, 8, 13, 21, 34]
    let rec: Vec<u64> = (0..10).map(fib_recursive).collect();
    println!("{:?}", rec);                                    // same
}
