// ============================================================
// Topic:  Data Structures  (FOCUS: maps, sets, stack, queue, heap, tuple)
// Summary: Built-in associative & LIFO/FIFO containers — method recall.
// Run:     dotnet script csharp/15_data_structures.cs
//
// KEY DIFFERENCES:
//   Maps:  dict / Map / Dictionary / HashMap / unordered_map
//   Sets:  set / Set / HashSet
//   Stack: list+append/pop (Py/TS) | std::stack | Stack<T> | Vec push/pop
//   Queue: collections.deque | std::queue | Queue<T> | VecDeque
//   Heap:  heapq module (min-heap on a list) | PriorityQueue<T> | BinaryHeap
// ============================================================

using System;
using System.Collections.Generic;
using System.Linq;

// ----- 1. Maps (Dictionary) — create, get, set, delete -----
var scores = new Dictionary<string, int> { ["alice"] = 90, ["bob"] = 85 };
Console.WriteLine(scores["alice"]);           // 90        | TS: map.get("alice") | Python: scores["alice"]
scores["carol"] = 88;                         // set       | TS: map.set("carol", 88) | Python: scores["carol"] = 88
Console.WriteLine(scores.GetValueOrDefault("dave", 0)); // 0 | TS: map.get("dave") ?? 0 | Python: scores.get("dave", 0)
scores.Remove("bob");                           // delete    | TS: map.delete("bob") | Python: del scores["bob"]
Console.WriteLine(scores.ContainsKey("bob")); // False     | TS: map.has("bob") | Python: "bob" in scores
Console.WriteLine($"[{string.Join(", ", scores.Keys)}]"); // ['alice', 'carol'] | Python: list(scores.keys())
Console.WriteLine(scores.Count);              // 2         | Python: len(scores)

// ----- 2. Sets — add, remove, set algebra -----
var tags = new HashSet<string> { "python", "rust" };
tags.Add("java");                             // add       | TS: set.add("java") | Python: tags.add("java")
tags.Remove("go");                            // remove (no error if missing) | Python: tags.discard("go")
Console.WriteLine(tags.Contains("rust"));     // True      | TS: set.has("rust") | Python: "rust" in tags
Console.WriteLine($"[{string.Join(", ", tags.Union(new[] { "cpp", "java" }))}]"); // union | Python: tags | {...}
Console.WriteLine($"[{string.Join(", ", tags.Intersect(new[] { "java", "go" }))}]"); // intersect | Python: tags & {...}
Console.WriteLine($"[{string.Join(", ", tags.Except(new[] { "java" }))}]"); // difference | Python: tags - {...}

// ----- 3. Stack (LIFO) — push / pop at top -----
var stack = new Stack<string>();
stack.Push("a");                              // push      | TS: stack.push("a") | Python: stack.append("a")
stack.Push("b");
string top = stack.Pop();                     // pop       | TS: stack.pop() | Python: stack.pop()
Console.WriteLine($"{top} [{string.Join(", ", stack)}]"); // b [a]

// ----- 4. Queue / Deque (FIFO) — enqueue right, dequeue left -----
var q = new Queue<string>();
q.Enqueue("first");                           // enqueue   | TS: queue.push("first") | Python: q.append("first")
q.Enqueue("second");
string front = q.Dequeue();                   // dequeue   | TS: queue.shift() | Python: q.popleft()
Console.WriteLine($"{front} [{string.Join(", ", q)}]"); // first [second]
var dq = new LinkedList<int>(new[] { 1, 2 });  // deque-like prepend | Python: deque([1, 2])
dq.AddFirst(0);                               // add front | TS: unshift | Python: dq.appendleft(0)
Console.WriteLine($"[{string.Join(", ", dq)}]"); // [0, 1, 2]

// ----- 5. Min-heap (PriorityQueue<int> — .NET 6+) -----
var heap = new PriorityQueue<int, int>();
foreach (int x in new[] { 5, 1, 3 })
    heap.Enqueue(x, x);                       // heapify   | Python: heapq.heapify(heap)
Console.WriteLine(heap.Dequeue());            // 1         | Python: heapq.heappop(heap)
heap.Enqueue(2, 2);                           // push      | Python: heapq.heappush(heap, 2)
Console.WriteLine(heap.Peek());               // 2         | peek min | Python: heap[0]

// ----- 6. Tuples — fixed-size pairs (ValueTuple) -----
var point = (10, 20);
Console.WriteLine($"{point.Item1} {point.Item2}"); // 10 20 | Python: point[0], point[1]
var (x, y) = point;                           // unpack    | Python: x, y = point
Console.WriteLine($"{x} {y}");                // 10 20
var pair = ("key", "value");                  // like a 2-field record | Python: ("key", "value")
Console.WriteLine(pair.Item1);                // key       | Python: pair[0]

// Cross-language note:
//   C# Dictionary preserves insertion order (.NET Core 3.0+); Python dict ordered (3.7+); TS Map too.
//   C# PriorityQueue<TElement,TPriority> is a built-in min-heap (.NET 6+) — unlike Python heapq on a list.
//   C# ValueTuple (x, y) is built-in; Java has no tuple — use record or array.
//   TS has no Stack/Queue class — use array push/pop and shift.