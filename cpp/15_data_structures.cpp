// ============================================================
// Topic:  Data Structures  (FOCUS: maps, sets, stack, queue, heap, tuple)
// Summary: Associative & LIFO/FIFO containers — method recall.
// Run:     g++ -std=c++17 cpp/15_data_structures.cpp -o cpp/15_data_structures && cpp/15_data_structures
//
// KEY DIFFERENCES:
//   Maps:  dict / Map / Dictionary / HashMap / unordered_map
//   Sets:  set / Set / HashSet / unordered_set
//   Stack: list+append/pop (Py/TS) | std::stack | Stack<T> | Vec push/pop
//   Queue: collections.deque | std::queue | Queue<T> | VecDeque
//   Heap:  heapq module (min-heap on a list) | priority_queue | BinaryHeap
// ============================================================

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <deque>
#include <tuple>
#include <algorithm>

void printSet(const std::unordered_set<std::string>& s) {
    std::vector<std::string> items(s.begin(), s.end());
    std::sort(items.begin(), items.end());
    std::cout << "{";
    for (size_t i = 0; i < items.size(); ++i) {
        if (i) std::cout << ", ";
        std::cout << items[i];
    }
    std::cout << "}";
}

int main() {
    // ----- 1. Maps (unordered_map) — create, get, set, delete -----
    std::unordered_map<std::string, int> scores = {{"alice", 90}, {"bob", 85}};
    std::cout << scores["alice"] << std::endl;
    // Output: 90        | TS: map.get("alice")
    scores["carol"] = 88;
    std::cout << (scores.count("dave") ? scores["dave"] : 0) << std::endl;
    // Output: 0         | TS: map.get("dave") ?? 0
    scores.erase("bob");
    std::cout << std::boolalpha << (scores.count("bob") > 0) << std::endl;
    // Output: false     | TS: map.has("bob")
    std::vector<std::string> keys;
    for (const auto& kv : scores) keys.push_back(kv.first);
    std::sort(keys.begin(), keys.end());
    std::cout << "[";
    for (size_t i = 0; i < keys.size(); ++i) {
        if (i) std::cout << ", ";
        std::cout << keys[i];
    }
    std::cout << "]" << std::endl;
    // Output: [alice, carol]
    std::cout << scores.size() << std::endl;
    // Output: 2

    // ----- 2. Sets — add, remove, set algebra -----
    std::unordered_set<std::string> tags = {"python", "rust"};
    tags.insert("java");
    tags.erase("go");
    std::cout << std::boolalpha << (tags.count("rust") > 0) << std::endl;
    // Output: true      | TS: set.has("rust")
    std::unordered_set<std::string> u = tags;
    u.insert("cpp");
    printSet(u);
    std::cout << std::endl;
    // Output: {cpp, java, python, rust}   | union
    std::unordered_set<std::string> inter;
    for (const auto& x : tags)
        if (x == "java" || x == "go") inter.insert(x);
    printSet(inter);
    std::cout << std::endl;
    // Output: {java}   | intersect
    std::unordered_set<std::string> diff;
    for (const auto& x : tags)
        if (x != "java") diff.insert(x);
    printSet(diff);
    std::cout << std::endl;
    // Output: {python, rust}   | difference

    // ----- 3. Stack (LIFO) — push / pop at top -----
    std::stack<std::string> stk;
    stk.push("a");
    stk.push("b");
    std::string top = stk.top();
    stk.pop();
    std::cout << top << " [";
    std::vector<std::string> stkContents;
    while (!stk.empty()) {
        stkContents.push_back(stk.top());
        stk.pop();
    }
    std::reverse(stkContents.begin(), stkContents.end());
    for (size_t i = 0; i < stkContents.size(); ++i) {
        if (i) std::cout << ", ";
        std::cout << "'" << stkContents[i] << "'";
    }
    std::cout << "]" << std::endl;
    // Output: b ['a']

    // ----- 4. Queue / Deque (FIFO) — push back, pop front -----
    std::queue<std::string> q;
    q.push("first");
    q.push("second");
    std::string front = q.front();
    q.pop();
    std::cout << front << " [";
    std::cout << "'" << q.front() << "'";
    std::cout << "]" << std::endl;
    // Output: first ['second']
    std::deque<int> dq = {1, 2};
    dq.push_front(0);
    std::cout << "[";
    for (size_t i = 0; i < dq.size(); ++i) {
        if (i) std::cout << ", ";
        std::cout << dq[i];
    }
    std::cout << "]" << std::endl;
    // Output: [0, 1, 2]

    // ----- 5. Min-heap (priority_queue with greater<int>) -----
    std::priority_queue<int, std::vector<int>, std::greater<int>> heap;
    for (int x : {5, 1, 3}) heap.push(x);
    std::cout << heap.top() << std::endl;
    heap.pop();
    // Output: 1         | pop smallest
    heap.push(2);
    std::cout << heap.top() << std::endl;
    // Output: 2         | peek min

    // ----- 6. Pair / Tuple — fixed-size pairs -----
    std::pair<int, int> point = {10, 20};
    std::cout << point.first << " " << point.second << std::endl;
    // Output: 10 20
    int x = point.first, y = point.second;
    std::cout << x << " " << y << std::endl;
    // Output: 10 20
    std::pair<std::string, std::string> kv = {"key", "value"};
    std::cout << kv.first << std::endl;
    // Output: key

    // Cross-language note:
    //   Python dict is ordered (3.7+); TS Map preserves insertion order too.
    //   C++ unordered_map has no guaranteed iteration order — sort keys for display.
    //   Python heapq is a module on a list — C++ uses priority_queue adapter.
    //   Python tuple is built-in; C++ has std::pair (2) and std::tuple (N).
    return 0;
}