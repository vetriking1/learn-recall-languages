// ============================================================
// Practice: Arrays
// Summary: max/min, sum/average, in-place reverse, remove dups.
// Run:     rustc practice/rust/arrays.rs -o practice/rust/arrays && practice/rust/arrays
// ============================================================

// ----- 1. Max and min of a slice -----
fn max_min(arr: &[i32]) -> (i32, i32) {
    let mut mx = arr[0];
    let mut mn = arr[0];
    for &x in arr {
        if x > mx { mx = x; }
        if x < mn { mn = x; }
    }
    (mx, mn)
}

// ----- 2. Sum and average -----
fn sum_avg(arr: &[i32]) -> (i32, f64) {
    let mut total = 0;
    for &x in arr { total += x; }
    (total, total as f64 / arr.len() as f64)
}

// ----- 3. Reverse in place (two-pointer swap) -----
fn reverse_in_place(arr: &mut Vec<i32>) {
    let (mut i, mut j) = (0, arr.len() - 1);
    while i < j {
        arr.swap(i, j);
        i += 1;
        j -= 1;
    }
}

// ----- 4. Remove duplicates from a SORTED slice -----
fn remove_duplicates(arr: &[i32]) -> Vec<i32> {
    let mut result: Vec<i32> = Vec::new();
    for &x in arr {
        if result.last() != Some(&x) {
            result.push(x);
        }
    }
    result
}

fn main() {
    println!("{:?}", max_min(&[3, 7, 1, 9, 2]));       // Output: (9, 1)
    println!("{:?}", sum_avg(&[10, 20, 30, 40]));      // Output: (100, 25.0)
    let mut v = vec![1, 2, 3, 4, 5];
    reverse_in_place(&mut v);
    println!("{:?}", v);                                // Output: [5, 4, 3, 2, 1]
    println!("{:?}", remove_duplicates(&[1, 1, 2, 2, 3, 4, 4, 5])); // [1, 2, 3, 4, 5]
}
