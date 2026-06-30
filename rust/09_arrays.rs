// ============================================================
// Topic:  Arrays / Vectors  (FOCUS: methods & operations)
// Summary: Vec<T> vs [T;N], push/pop, map/filter, sort, search.
// Run:     rustc rust/09_arrays.rs -o rust/09_arrays && rust/09_arrays
//
// KEY DIFFERENCE the user cares about:
//   Rust: Vec::push(), .pop()   |   Python: .append(), .pop()   |   TS: .push(), .pop()
//   Rust: [T; N] fixed array vs Vec<T> growable
// ============================================================

fn main() {
    // ----- 1. Fixed array [T; N] vs growable Vec<T> -----
    let fixed: [i32; 3] = [10, 20, 30]; // stack, fixed size at compile time
    let mut vec = vec![10, 20, 30]; // heap, growable (like Python list / TS array)
    println!("fixed: {:?}  vec: {:?}", fixed, vec);
    // Output: fixed: [10, 20, 30]  vec: [10, 20, 30]

    // ----- 2. Access -----
    println!("{}", vec[0]); // 10     | Python: l[0]   TS: l[0]
    println!("{}", vec[vec.len() - 1]); // 30   (no negative indexing)
    println!("{}", vec.len()); // 3      | Python: len(l)   TS: l.length

    // ----- 3. Add to END -----
    vec.push(40); // [10,20,30,40]   | Python: l.append(40)   TS: l.push(40)
    println!("{:?}", vec); // Output: [10, 20, 30, 40]

    vec.extend([50, 60]); // add many
    println!("{:?}", vec); // Output: [10, 20, 30, 40, 50, 60]

    // ----- 4. Add to FRONT -----
    vec.insert(0, 5); // [5,10,...]       | Python: l.insert(0, 5)   TS: l.unshift(5)
    println!("{:?}", vec); // Output: [5, 10, 20, 30, 40, 50, 60]

    // ----- 5. Remove from END -----
    let last = vec.pop(); // removes & returns Some(60)   | TS: l.pop()
    println!("{:?} {:?}", last, vec); // Output: Some(60) [5, 10, 20, 30, 40, 50]

    // ----- 6. Remove from FRONT -----
    let first = vec.remove(0); // removes index 0        | Python: l.pop(0)   TS: l.shift()
    println!("{} {:?}", first, vec); // Output: 5 [10, 20, 30, 40, 50]

    // ----- 7. Remove by VALUE -----
    vec.retain(|&x| x != 30); // keep elements != 30   | Python: l.remove(30)
    println!("{:?}", vec); // Output: [10, 20, 40, 50]

    // ----- 8. Slicing -----
    println!("{:?}", &vec[1..3]); // [20, 40]   | Python: l[1:3]   TS: l.slice(1, 3)
    let reversed: Vec<i32> = vec.iter().rev().copied().collect();
    println!("{:?}", reversed); // Output: [50, 40, 20, 10]

    // ----- 9. Search / membership -----
    println!("{}", vec.contains(&20)); // true   | Python: 20 in l   TS: l.includes(20)
    println!("{:?}", vec.iter().position(|&x| x == 40)); // Some(2)   | TS: indexOf(40)
    println!("{}", vec.iter().filter(|&&x| x == 10).count()); // 1

    // ----- 10. Transform: map / filter / sum -----
    let nums = vec![1, 2, 3, 4];
    let doubled: Vec<i32> = nums.iter().map(|x| x * 2).collect();
    println!("{:?}", doubled); // Output: [2, 4, 6, 8]

    let evens: Vec<i32> = nums.iter().filter(|x| *x % 2 == 0).copied().collect();
    println!("{:?}", evens); // Output: [2, 4]

    let total: i32 = nums.iter().sum();
    println!("{}", total); // Output: 10

    // ----- 11. Sort -----
    let mut vals = vec![3, 1, 4, 1, 5];
    vals.sort(); // in place             | TS: vals.sort((a,b)=>a-b)
    println!("{:?}", vals); // Output: [1, 1, 3, 4, 5]

    let mut desc = vals.clone();
    desc.sort_by(|a, b| b.cmp(a)); // descending
    println!("{:?}", desc); // Output: [5, 4, 3, 1, 1]

    // ----- Quick reference table (Rust -> Python/TS) -----
    // vec.len()              -> len(l) / l.length
    // vec.push(x)            -> l.append(x) / l.push(x)
    // vec.pop()              -> l.pop() / l.pop()          (both remove from END)
    // vec.insert(0, x)       -> l.insert(0, x) / l.unshift(x)
    // vec.remove(0)          -> l.pop(0) / l.shift()
    // vec.contains(&x)       -> x in l / l.includes(x)
    // vec.iter().position()  -> l.index(x) / l.indexOf(x)
    // iter().map().collect() -> [f(x) for x in l] / l.map(f)
    // iter().filter().collect() -> [x for x in l if ...] / l.filter(...)
    // vec.sort()             -> l.sort() / l.sort((a,b)=>a-b)
}