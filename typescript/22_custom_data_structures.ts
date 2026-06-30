// ============================================================
// Topic:  Custom Data Structures  (FOCUS: linked list, tree, graph)
// Summary: Singly linked list, binary tree traversals, graph adjacency list + BFS/DFS.
// Run:     npx ts-node typescript/22_custom_data_structures.ts
//
// KEY DIFFERENCES:
//   Python:  class Node + manual pointers; no built-in linked list
//   TS/JS:   same pointer style; Map or Record for adjacency list
//   Rust:    Box<Node> / Rc<RefCell<Node>>; Vec<Vec<usize>> for graph
//   Java:    class Node { Node next; } ; HashMap<Integer, List<Integer>>
//   C++:     struct Node* next; vector<vector<int>> adj
// ============================================================

// ----- 1. Singly linked list -----
class ListNode {
  constructor(
    public value: number,
    public next: ListNode | null = null
  ) {}
}

class LinkedList {
  private head: ListNode | null = null;

  append(value: number): void {
    const node = new ListNode(value);
    if (!this.head) {
      this.head = node;
      return;
    }
    let current = this.head;
    while (current.next) {
      current = current.next;
    }
    current.next = node;
  }

  toArray(): number[] {
    const result: number[] = [];
    let current = this.head;
    while (current) {
      result.push(current.value);
      current = current.next;
    }
    return result;
  }

  reverse(): void {
    let prev: ListNode | null = null;
    let current = this.head;
    while (current) {
      const next = current.next;
      current.next = prev;
      prev = current;
      current = next;
    }
    this.head = prev;
  }
}

// ----- 2. Binary tree (recursive traversals) -----
class TreeNode {
  constructor(
    public value: number,
    public left: TreeNode | null = null,
    public right: TreeNode | null = null
  ) {}
}

function inorder(node: TreeNode | null, out: number[] = []): number[] {
  if (!node) return out;
  inorder(node.left, out);
  out.push(node.value);
  inorder(node.right, out);
  return out;
}

function preorder(node: TreeNode | null, out: number[] = []): number[] {
  if (!node) return out;
  out.push(node.value);
  preorder(node.left, out);
  preorder(node.right, out);
  return out;
}

function postorder(node: TreeNode | null, out: number[] = []): number[] {
  if (!node) return out;
  postorder(node.left, out);
  postorder(node.right, out);
  out.push(node.value);
  return out;
}

// ----- 3. Graph — adjacency list (Map) + BFS / DFS -----
class Graph {
  private adj = new Map<number, number[]>();

  addEdge(u: number, v: number): void {
    if (!this.adj.has(u)) this.adj.set(u, []);
    if (!this.adj.has(v)) this.adj.set(v, []);
    this.adj.get(u)!.push(v);
    this.adj.get(v)!.push(u);
  }

  bfs(start: number): number[] {
    const visited = new Set<number>();
    const queue: number[] = [start];
    const order: number[] = [];
    visited.add(start);

    while (queue.length > 0) {
      const node = queue.shift()!;
      order.push(node);
      for (const neighbor of this.adj.get(node) ?? []) {
        if (!visited.has(neighbor)) {
          visited.add(neighbor);
          queue.push(neighbor);
        }
      }
    }
    return order;
  }

  dfs(start: number): number[] {
    const visited = new Set<number>();
    const order: number[] = [];

    const visit = (node: number): void => {
      visited.add(node);
      order.push(node);
      for (const neighbor of this.adj.get(node) ?? []) {
        if (!visited.has(neighbor)) {
          visit(neighbor);
        }
      }
    };

    visit(start);
    return order;
  }
}

// ----- Demo: linked list -----
const list = new LinkedList();
for (const n of [1, 2, 3, 4, 5]) {
  list.append(n);
}
console.log(`list: ${list.toArray().join(" ")}`); // Output: list: 1 2 3 4 5

list.reverse();
console.log(`reversed: ${list.toArray().join(" ")}`); // Output: reversed: 5 4 3 2 1

// ----- Demo: binary tree — root 1, left 2 (4, 5), right 3 -----
const tree = new TreeNode(
  1,
  new TreeNode(2, new TreeNode(4), new TreeNode(5)),
  new TreeNode(3)
);
console.log(`inorder: ${inorder(tree).join(" ")}`); // Output: inorder: 4 2 5 1 3
console.log(`preorder: ${preorder(tree).join(" ")}`); // Output: preorder: 1 2 4 5 3
console.log(`postorder: ${postorder(tree).join(" ")}`); // Output: postorder: 4 5 2 3 1

// ----- Demo: graph — 0:[1,2], 1:[0,3], 2:[0,4], 3:[1], 4:[2] -----
const graph = new Graph();
graph.addEdge(0, 1);
graph.addEdge(0, 2);
graph.addEdge(1, 3);
graph.addEdge(2, 4);
console.log(`bfs: ${graph.bfs(0).join(" ")}`); // Output: bfs: 0 1 2 3 4
console.log(`dfs: ${graph.dfs(0).join(" ")}`); // Output: dfs: 0 1 3 2 4

// Cross-language note:
//   Linked list: TS uses nullable references (Node | null) like Java/C++ pointers.
//   Tree traversals: recursive style matches Python/Rust; iterative uses explicit stack.
//   Graph adjacency: Map<number, number[]> == Python dict[int, list[int]] / Java HashMap.