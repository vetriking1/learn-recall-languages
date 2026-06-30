# ============================================================
# Topic:  Data Structures  (FOCUS: maps, sets, stack, queue, heap, tuple)
# Summary: Built-in associative & LIFO/FIFO containers — method recall.
# Run:     python python/15_data_structures.py
#
# KEY DIFFERENCES:
#   Maps:  dict / Map / Dictionary / HashMap / unordered_map
#   Sets:  set / Set / HashSet
#   Stack: list+append/pop (Py/TS) | std::stack | Stack<T> | Vec push/pop
#   Queue: collections.deque | std::queue | Queue<T> | VecDeque
#   Heap:  heapq module (min-heap on a list) | priority_queue | BinaryHeap
# ============================================================

import heapq
from collections import deque

# ----- 1. Maps (dict) — create, get, set, delete -----
scores = {"alice": 90, "bob": 85}
print(scores["alice"])           # 90        | TS: map.get("alice")
scores["carol"] = 88             # set       | TS: map.set("carol", 88)
print(scores.get("dave", 0))     # 0         | TS: map.get("dave") ?? 0
del scores["bob"]                # delete    | TS: map.delete("bob")
print("bob" in scores)           # False     | TS: map.has("bob")
print(list(scores.keys()))       # ['alice', 'carol']
print(len(scores))               # 2

# ----- 2. Sets — add, remove, set algebra -----
tags = {"python", "rust"}
tags.add("java")                 # add       | TS: set.add("java")
tags.discard("go")               # remove (no error if missing)
print("rust" in tags)            # True      | TS: set.has("rust")
print(tags | {"cpp", "java"})    # union     | TS: new Set([...tags, "cpp"])
print(tags & {"java", "go"})     # intersect | TS: filter in set
print(tags - {"java"})           # difference

# ----- 3. Stack (LIFO) — push / pop at end -----
stack = []
stack.append("a")                # push      | TS: stack.push("a")
stack.append("b")
top = stack.pop()                # pop       | TS: stack.pop()
print(top, stack)                # b ['a']

# ----- 4. Queue / Deque (FIFO) — append right, pop left -----
q = deque()
q.append("first")                # enqueue   | TS: queue.push("first")
q.append("second")
front = q.popleft()              # dequeue   | TS: queue.shift()
print(front, list(q))            # first ['second']
dq = deque([1, 2])
dq.appendleft(0)                 # add front | TS: unshift
print(list(dq))                  # [0, 1, 2]

# ----- 5. Min-heap (heapq operates on a list in place) -----
heap = [5, 1, 3]
heapq.heapify(heap)              # [1, 5, 3] internally
print(heapq.heappop(heap))       # 1         | pop smallest
heapq.heappush(heap, 2)
print(heap[0])                   # 2         | peek min = heap[0]

# ----- 6. Tuples — fixed-size, immutable pairs -----
point = (10, 20)
print(point[0], point[1])        # 10 20
x, y = point                     # unpack
print(x, y)                      # 10 20
pair = ("key", "value")          # like a 2-field record
print(pair[0])                   # key

# Cross-language note:
#   Python dict is ordered (3.7+); TS Map preserves insertion order too.
#   Python heapq is a module on a list — not a separate Heap type.
#   Python tuple is built-in; Java has no tuple — use record or array.
#   TS has no Stack/Queue class — use array push/pop and shift.