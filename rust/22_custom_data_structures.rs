// ============================================================
// Topic:  Custom Data Structures  (FOCUS: linked list, tree, graph)
// Summary: Box-backed list and BST; adjacency-list graph with BFS/DFS.
// Run:     rustc --edition 2021 rust/22_custom_data_structures.rs -o rust/22_custom_data_structures.exe && rust/22_custom_data_structures.exe
//
// KEY DIFFERENCES:
//   Python:  class Node with references; list built-in; no Box
//   TS/JS:   object references; no explicit ownership
//   Rust:    Box<T> for heap-owned nodes; Option<Box<T>> for nullable links
//   Java:    class Node { Node next; } — GC manages heap
//   C++:     raw pointers or unique_ptr for tree/list nodes
// ============================================================

use std::collections::VecDeque;

// ----- 1. Singly linked list (Box-backed nodes) -----
struct ListNode {
    val: i32,
    next: Option<Box<ListNode>>,
}

struct LinkedList {
    head: Option<Box<ListNode>>,
}

impl LinkedList {
    fn new() -> Self {
        LinkedList { head: None }
    }

    fn push_back(&mut self, val: i32) {
        let new_node = Box::new(ListNode { val, next: None });
        if self.head.is_none() {
            self.head = Some(new_node);
            return;
        }
        let mut cur = self.head.as_mut().unwrap();
        while cur.next.is_some() {
            cur = cur.next.as_mut().unwrap();
        }
        cur.next = Some(new_node);
    }

    fn to_vec(&self) -> Vec<i32> {
        let mut out = Vec::new();
        let mut cur = self.head.as_ref();
        while let Some(node) = cur {
            out.push(node.val);
            cur = node.next.as_ref();
        }
        out
    }

    fn reverse(&mut self) {
        let mut prev: Option<Box<ListNode>> = None;
        let mut cur = self.head.take();
        while let Some(mut node) = cur {
            let next = node.next.take();
            node.next = prev;
            prev = Some(node);
            cur = next;
        }
        self.head = prev;
    }
}

// ----- 2. Binary tree (Box-backed nodes) -----
struct TreeNode {
    val: i32,
    left: Option<Box<TreeNode>>,
    right: Option<Box<TreeNode>>,
}

struct BinaryTree {
    root: Option<Box<TreeNode>>,
}

impl BinaryTree {
    // Manual build: root 1, left 2 (children 4, 5), right 3
    fn sample() -> Self {
        BinaryTree {
            root: Some(Box::new(TreeNode {
                val: 1,
                left: Some(Box::new(TreeNode {
                    val: 2,
                    left: Some(Box::new(TreeNode {
                        val: 4,
                        left: None,
                        right: None,
                    })),
                    right: Some(Box::new(TreeNode {
                        val: 5,
                        left: None,
                        right: None,
                    })),
                })),
                right: Some(Box::new(TreeNode {
                    val: 3,
                    left: None,
                    right: None,
                })),
            })),
        }
    }

    fn inorder(&self) -> Vec<i32> {
        let mut out = Vec::new();
        Self::inorder_node(self.root.as_ref(), &mut out);
        out
    }

    fn inorder_node(node: Option<&Box<TreeNode>>, out: &mut Vec<i32>) {
        if let Some(n) = node {
            Self::inorder_node(n.left.as_ref(), out);
            out.push(n.val);
            Self::inorder_node(n.right.as_ref(), out);
        }
    }

    fn preorder(&self) -> Vec<i32> {
        let mut out = Vec::new();
        Self::preorder_node(self.root.as_ref(), &mut out);
        out
    }

    fn preorder_node(node: Option<&Box<TreeNode>>, out: &mut Vec<i32>) {
        if let Some(n) = node {
            out.push(n.val);
            Self::preorder_node(n.left.as_ref(), out);
            Self::preorder_node(n.right.as_ref(), out);
        }
    }

    fn postorder(&self) -> Vec<i32> {
        let mut out = Vec::new();
        Self::postorder_node(self.root.as_ref(), &mut out);
        out
    }

    fn postorder_node(node: Option<&Box<TreeNode>>, out: &mut Vec<i32>) {
        if let Some(n) = node {
            Self::postorder_node(n.left.as_ref(), out);
            Self::postorder_node(n.right.as_ref(), out);
            out.push(n.val);
        }
    }
}

// ----- 3. Graph (adjacency list: Vec<Vec<usize>>) -----
struct Graph {
    adj: Vec<Vec<usize>>,
}

impl Graph {
    fn new(n: usize) -> Self {
        Graph {
            adj: vec![Vec::new(); n],
        }
    }

    fn add_edge(&mut self, u: usize, v: usize) {
        self.adj[u].push(v);
        self.adj[v].push(u);
    }

    fn bfs(&self, start: usize) -> Vec<usize> {
        let mut visited = vec![false; self.adj.len()];
        let mut queue = VecDeque::new();
        let mut out = Vec::new();

        visited[start] = true;
        queue.push_back(start);

        while let Some(node) = queue.pop_front() {
            out.push(node);
            for &next in &self.adj[node] {
                if !visited[next] {
                    visited[next] = true;
                    queue.push_back(next);
                }
            }
        }
        out
    }

    fn dfs(&self, start: usize) -> Vec<usize> {
        let mut visited = vec![false; self.adj.len()];
        let mut out = Vec::new();
        self.dfs_visit(start, &mut visited, &mut out);
        out
    }

    fn dfs_visit(&self, node: usize, visited: &mut [bool], out: &mut Vec<usize>) {
        visited[node] = true;
        out.push(node);
        for &next in &self.adj[node] {
            if !visited[next] {
                self.dfs_visit(next, visited, out);
            }
        }
    }
}

fn print_nums(label: &str, nums: &[i32]) {
    print!("{}:", label);
    for n in nums {
        print!(" {}", n);
    }
    println!();
}

fn print_usize(label: &str, nums: &[usize]) {
    print!("{}:", label);
    for n in nums {
        print!(" {}", n);
    }
    println!();
}

fn main() {
    // Linked list: 1 -> 2 -> 3 -> 4 -> 5
    let mut list = LinkedList::new();
    for v in [1, 2, 3, 4, 5] {
        list.push_back(v);
    }
    print_nums("list", &list.to_vec());
    list.reverse();
    print_nums("reversed", &list.to_vec());

    let tree = BinaryTree::sample();
    print_nums("inorder", &tree.inorder());
    print_nums("preorder", &tree.preorder());
    print_nums("postorder", &tree.postorder());

    // Undirected graph on 5 nodes (0..4)
    let mut graph = Graph::new(5);
    graph.add_edge(0, 1);
    graph.add_edge(0, 2);
    graph.add_edge(1, 3);
    graph.add_edge(1, 2);
    graph.add_edge(2, 4);

    print_usize("bfs", &graph.bfs(0));
    print_usize("dfs", &graph.dfs(0));
}