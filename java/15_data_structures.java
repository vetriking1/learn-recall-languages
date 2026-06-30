// ============================================================
// Topic:  Data Structures  (FOCUS: maps, sets, stack, queue, heap, tuple)
// Summary: HashMap, HashSet, ArrayDeque, PriorityQueue, pair/tuple.
// Run:     java java/15_data_structures.java   (Java 11+ single-file launch)
//
// KEY DIFFERENCES:
//   Maps:  dict / Map / Dictionary / HashMap / unordered_map
//   Sets:  set / Set / HashSet
//   Stack: list+append/pop (Py/TS) | ArrayDeque push/pop | std::stack
//   Queue: collections.deque | ArrayDeque offer/poll | std::queue
//   Heap:  heapq module (min-heap on a list) | PriorityQueue
//   Tuple: Python tuple | Java record or int[]
// ============================================================

import java.util.ArrayDeque;
import java.util.Deque;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedHashMap;
import java.util.LinkedHashSet;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Set;

public class DataStructures {
    // ----- 6. Tuple-like pair (Java 16+ record) -----
    record Pair(String key, String value) {}

    public static void main(String[] args) {
        // ----- 1. Maps (HashMap) — create, get, set, delete -----
        Map<String, Integer> scores = new LinkedHashMap<>();
        scores.put("alice", 90);
        scores.put("bob", 85);
        System.out.println(scores.get("alice"));              // Output: 90
        scores.put("carol", 88);                                // set
        System.out.println(scores.getOrDefault("dave", 0));     // Output: 0
        scores.remove("bob");                                   // delete
        System.out.println(scores.containsKey("bob"));          // Output: false
        System.out.println(scores.keySet());                    // Output: [alice, carol]
        System.out.println(scores.size());                      // Output: 2

        // ----- 2. Sets (HashSet) — add, remove, set algebra -----
        Set<String> tags = new LinkedHashSet<>();
        tags.add("python");
        tags.add("rust");
        tags.add("java");                                       // add
        tags.remove("go");                                      // remove (no error if missing)
        System.out.println(tags.contains("rust"));              // Output: true
        Set<String> union = new LinkedHashSet<>(tags);
        union.addAll(Set.of("cpp", "java"));
        System.out.println(union);                              // Output: [python, rust, java, cpp]
        Set<String> intersect = new LinkedHashSet<>(tags);
        intersect.retainAll(Set.of("java", "go"));
        System.out.println(intersect);                          // Output: [java]
        Set<String> difference = new LinkedHashSet<>(tags);
        difference.removeAll(Set.of("java"));
        System.out.println(difference);                         // Output: [python, rust]

        // ----- 3. Stack (LIFO) — ArrayDeque push / pop at end -----
        Deque<String> stack = new ArrayDeque<>();
        stack.push("a");                                        // push
        stack.push("b");
        String top = stack.pop();                               // pop
        System.out.println(top + " " + stack);                  // Output: b [a]

        // ----- 4. Queue / Deque (FIFO) — offer right, poll left -----
        Deque<String> q = new ArrayDeque<>();
        q.offerLast("first");                                   // enqueue
        q.offerLast("second");
        String front = q.pollFirst();                           // dequeue
        System.out.println(front + " " + q);                    // Output: first [second]
        Deque<Integer> dq = new ArrayDeque<>();
        dq.offerLast(1);
        dq.offerLast(2);
        dq.offerFirst(0);                                       // add front
        System.out.println(dq);                                 // Output: [0, 1, 2]

        // ----- 5. Min-heap (PriorityQueue) -----
        Queue<Integer> heap = new PriorityQueue<>();
        heap.offer(5);
        heap.offer(1);
        heap.offer(3);
        System.out.println(heap.poll());                        // Output: 1
        heap.offer(2);
        System.out.println(heap.peek());                        // Output: 2

        // ----- 6. Tuples — fixed-size pairs (record or int[]) -----
        int[] point = {10, 20};
        System.out.println(point[0] + " " + point[1]);          // Output: 10 20
        int x = point[0], y = point[1];                         // unpack
        System.out.println(x + " " + y);                        // Output: 10 20
        Pair pair = new Pair("key", "value");                   // like a 2-field record
        System.out.println(pair.key());                         // Output: key

        // Cross-language note:
        //   Use LinkedHashMap for insertion-order keys (like Python 3.7+ dict).
        //   HashSet has no guaranteed iteration order; LinkedHashSet preserves add order.
        //   ArrayDeque is the preferred stack/queue — no synchronized overhead of Stack class.
        //   PriorityQueue is a min-heap by default; peek() reads min without removing.
        //   Java has no built-in tuple — use record (Java 16+) or int[] for pairs.
    }
}