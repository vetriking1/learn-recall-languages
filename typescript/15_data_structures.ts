// ============================================================
// Topic:  Data Structures  (FOCUS: maps, sets, stack, queue, heap, tuple)
// Summary: Built-in associative & LIFO/FIFO containers — method recall.
// Run:     npx ts-node typescript/15_data_structures.ts
//
// KEY DIFFERENCES:
//   Maps:  dict / Map / Dictionary / HashMap / unordered_map
//   Sets:  set / Set / HashSet
//   Stack: list+append/pop (Py/TS) | std::stack | Stack<T> | Vec push/pop
//   Queue: collections.deque | std::queue | Queue<T> | VecDeque
//   Heap:  heapq module (min-heap on a list) | priority_queue | BinaryHeap
//         ⚠ TS has no built-in heap — use a small MinHeap class or sorted array.
// ============================================================

// ----- 1. Maps (Map) — create, get, set, delete -----
const scores = new Map<string, number>([
  ["alice", 90],
  ["bob", 85],
]);
console.log(scores.get("alice")); // Output: 90        | Python: scores["alice"]
scores.set("carol", 88); // set       | Python: scores["carol"] = 88
console.log(scores.get("dave") ?? 0); // Output: 0         | Python: scores.get("dave", 0)
scores.delete("bob"); // delete    | Python: del scores["bob"]
console.log(scores.has("bob")); // Output: false     | Python: "bob" in scores
console.log([...scores.keys()]); // Output: [ 'alice', 'carol' ]
console.log(scores.size); // Output: 2         | Python: len(scores)

// ----- 2. Sets — add, remove, set algebra -----
const tags = new Set(["python", "rust"]);
tags.add("java"); // add       | Python: tags.add("java")
tags.delete("go"); // discard (no error if missing) | Python: tags.discard("go")
console.log(tags.has("rust")); // Output: true      | Python: "rust" in tags
console.log(new Set([...tags, "cpp", "java"])); // Output: Set(4) { 'python', 'rust', 'java', 'cpp' }  union
console.log(new Set([...tags].filter((x) => new Set(["java", "go"]).has(x)))); // Output: Set(1) { 'java' }  intersect
console.log(new Set([...tags].filter((x) => x !== "java"))); // Output: Set(2) { 'python', 'rust' }  difference

// ----- 3. Stack (LIFO) — push / pop at end -----
const stack: string[] = [];
stack.push("a"); // push      | Python: stack.append("a")
stack.push("b");
const top = stack.pop(); // pop       | Python: stack.pop()
console.log(top, stack); // Output: b [ 'a' ]

// ----- 4. Queue (FIFO) — push right, shift left -----
const queue: string[] = [];
queue.push("first"); // enqueue   | Python: q.append("first")
queue.push("second");
const front = queue.shift(); // dequeue   | Python: q.popleft()
console.log(front, queue); // Output: first [ 'second' ]
const dq = [1, 2];
dq.unshift(0); // add front | Python: dq.appendleft(0)
console.log(dq); // Output: [ 0, 1, 2 ]

// ----- 5. Min-heap (TS has no std heap — small inline MinHeap) -----
class MinHeap {
  private heap: number[] = [];

  heapify(items: number[]): void {
    this.heap = [...items];
    for (let i = Math.floor(this.heap.length / 2) - 1; i >= 0; i--) {
      this.siftDown(i);
    }
  }

  private siftDown(i: number): void {
    const n = this.heap.length;
    while (true) {
      let smallest = i;
      const left = 2 * i + 1;
      const right = 2 * i + 2;
      if (left < n && this.heap[left] < this.heap[smallest]) smallest = left;
      if (right < n && this.heap[right] < this.heap[smallest]) smallest = right;
      if (smallest === i) break;
      [this.heap[i], this.heap[smallest]] = [this.heap[smallest], this.heap[i]];
      i = smallest;
    }
  }

  private siftUp(i: number): void {
    while (i > 0) {
      const parent = Math.floor((i - 1) / 2);
      if (this.heap[i] >= this.heap[parent]) break;
      [this.heap[i], this.heap[parent]] = [this.heap[parent], this.heap[i]];
      i = parent;
    }
  }

  push(val: number): void {
    this.heap.push(val);
    this.siftUp(this.heap.length - 1);
  }

  pop(): number {
    const top = this.heap[0];
    const last = this.heap.pop()!;
    if (this.heap.length > 0) {
      this.heap[0] = last;
      this.siftDown(0);
    }
    return top;
  }

  peek(): number {
    return this.heap[0];
  }
}

const heap = new MinHeap();
heap.heapify([5, 1, 3]); // [1, 5, 3] internally  | Python: heapq.heapify(heap)
console.log(heap.pop()); // Output: 1         | Python: heapq.heappop(heap)
heap.push(2);
console.log(heap.peek()); // Output: 2         | Python: heap[0]  (peek min)

// ----- 6. Tuples — fixed-size typed pairs [T, U] -----
const point: [number, number] = [10, 20];
console.log(point[0], point[1]); // Output: 10 20
const [x, y] = point; // unpack
console.log(x, y); // Output: 10 20
const pair: [string, string] = ["key", "value"]; // like a 2-field record
console.log(pair[0]); // Output: key

// Cross-language note:
//   Python dict is ordered (3.7+); TS Map preserves insertion order too.
//   Python heapq is a module on a list — not a separate Heap type.
//   TS has no built-in Stack/Queue/Heap — use array push/pop/shift or a small class.
//   Python tuple is built-in; Java has no tuple — use record or array.