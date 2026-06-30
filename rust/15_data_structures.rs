// ============================================================
// Topic:  Data Structures  (FOCUS: maps, sets, stack, queue, heap, tuple)
// Summary: HashMap, HashSet, Vec stack, VecDeque queue, BinaryHeap min-heap.
// Run:     rustc rust/15_data_structures.rs -o rust/15_data_structures && rust/15_data_structures
//
// KEY DIFFERENCES:
//   Maps:  dict / Map / Dictionary / HashMap / unordered_map
//   Sets:  set / Set / HashSet
//   Stack: list+append/pop (Py/TS) | std::stack | Stack<T> | Vec push/pop
//   Queue: collections.deque | std::queue | Queue<T> | VecDeque
//   Heap:  heapq module (min-heap on a list) | priority_queue | BinaryHeap
// ============================================================

use std::cmp::Reverse;
use std::collections::{BinaryHeap, HashMap, HashSet, VecDeque};

fn main() {
    // ----- 1. Maps (HashMap) — create, get, set, delete -----
    let mut scores = HashMap::new();
    scores.insert("alice", 90);
    scores.insert("bob", 85);
    println!("{}", scores["alice"]); // 90        | Python: scores["alice"]
    // Output: 90

    scores.insert("carol", 88); // set       | Python: scores["carol"] = 88
    println!("{}", scores.get("dave").copied().unwrap_or(0)); // 0   | Python: scores.get("dave", 0)
    // Output: 0

    scores.remove("bob"); // delete    | Python: del scores["bob"]
    println!("{}", scores.contains_key("bob")); // False   | Python: "bob" in scores
    // Output: false

    let mut keys: Vec<&str> = scores.keys().copied().collect();
    keys.sort();
    println!("{:?}", keys); // ['alice', 'carol']   | Python: list(scores.keys())
    // Output: ["alice", "carol"]

    println!("{}", scores.len()); // 2         | Python: len(scores)
    // Output: 2

    // ----- 2. Sets — add, remove, set algebra -----
    let mut tags: HashSet<&str> = HashSet::from(["python", "rust"]);
    tags.insert("java"); // add       | Python: tags.add("java")
    tags.remove("go"); // remove (no error if missing)   | Python: tags.discard("go")
    println!("{}", tags.contains("rust")); // True   | Python: "rust" in tags
    // Output: true

    let other_union: HashSet<&str> = HashSet::from(["cpp", "java"]);
    let union: HashSet<&str> = tags.union(&other_union).copied().collect();
    println!("{:?}", union); // union     | Python: tags | {"cpp", "java"}
    // Output: {"cpp", "java", "python", "rust"}

    let other_intersect: HashSet<&str> = HashSet::from(["java", "go"]);
    let intersect: HashSet<&str> = tags.intersection(&other_intersect).copied().collect();
    println!("{:?}", intersect); // intersect | Python: tags & {"java", "go"}
    // Output: {"java"}

    let other_diff: HashSet<&str> = HashSet::from(["java"]);
    let difference: HashSet<&str> = tags.difference(&other_diff).copied().collect();
    println!("{:?}", difference); // difference | Python: tags - {"java"}
    // Output: {"python", "rust"}

    // ----- 3. Stack (LIFO) — push / pop at end -----
    let mut stack: Vec<&str> = Vec::new();
    stack.push("a"); // push      | Python: stack.append("a")
    stack.push("b");
    let top = stack.pop().unwrap(); // pop   | Python: stack.pop()
    println!("{} {:?}", top, stack); // b ['a']
    // Output: b ["a"]

    // ----- 4. Queue / Deque (FIFO) — append right, pop left -----
    let mut q = VecDeque::new();
    q.push_back("first"); // enqueue   | Python: q.append("first")
    q.push_back("second");
    let front = q.pop_front().unwrap(); // dequeue | Python: q.popleft()
    println!("{} {:?}", front, q); // first ['second']
    // Output: first ["second"]

    let mut dq: VecDeque<i32> = VecDeque::from([1, 2]);
    dq.push_front(0); // add front | Python: dq.appendleft(0)
    println!("{:?}", dq); // [0, 1, 2]
    // Output: [0, 1, 2]

    // ----- 5. Min-heap (BinaryHeap + Reverse for smallest-first) -----
    let mut heap = BinaryHeap::new();
    for x in [5, 1, 3] {
        heap.push(Reverse(x)); // heapify   | Python: heapq.heapify(heap)
    }
    println!("{}", heap.pop().unwrap().0); // 1   | Python: heapq.heappop(heap)
    // Output: 1

    heap.push(Reverse(2)); // push      | Python: heapq.heappush(heap, 2)
    println!("{}", heap.peek().unwrap().0); // 2   | Python: heap[0]  (peek min)
    // Output: 2

    // ----- 6. Tuples — fixed-size, immutable pairs -----
    let point = (10, 20);
    println!("{} {}", point.0, point.1); // 10 20   | Python: point[0], point[1]
    // Output: 10 20

    let (x, y) = point; // unpack
    println!("{} {}", x, y); // 10 20
    // Output: 10 20

    let pair = ("key", "value"); // like a 2-field record
    println!("{}", pair.0); // key
    // Output: key

    // Cross-language note:
    //   Python dict is ordered (3.7+); Rust HashMap iteration order is not stable.
    //   Python heapq is a module on a list — Rust BinaryHeap is max-heap; use Reverse for min.
    //   Python tuple is built-in; Rust (T, U) is a fixed anonymous product type.
    //   TS has no Stack/Queue class — use array push/pop and shift.
}