// ============================================================
// Topic:  Custom Data Structures  (FOCUS: linked list, tree, graph)
// Summary: Hand-rolled ListNode, TreeNode; list reverse; tree traversals;
//          graph BFS (Queue) and DFS (Deque).
// Run:     java java/22_custom_data_structures.java   (Java 11+ single-file launch)
//
// KEY DIFFERENCES:
//   Python:  class Node; list built from objects; deque for BFS/DFS
//   TS/JS:   { val, next } / { val, left, right }; Array for queue
//   Rust:    Box<Node> or Rc<RefCell<Node>>; VecDeque for BFS
//   Java:    static nested classes; ArrayDeque implements Queue + Deque
//   C++:     struct Node*; std::queue / std::stack or std::deque
// ============================================================

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;
import java.util.Queue;

public class CustomDataStructures {

    // ----- ListNode — singly linked list cell -----
    static class ListNode {
        int val;
        ListNode next;

        ListNode(int val) {
            this.val = val;
        }
    }

    // ----- TreeNode — binary tree cell -----
    static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int val) {
            this.val = val;
        }
    }

    // ----- 1. Linked list — build, print, reverse -----
    static ListNode buildList(int[] values) {
        if (values.length == 0) return null;
        ListNode head = new ListNode(values[0]);
        ListNode current = head;
        for (int i = 1; i < values.length; i++) {
            current.next = new ListNode(values[i]);
            current = current.next;
        }
        return head;
    }

    static String formatList(ListNode head) {
        StringBuilder sb = new StringBuilder();
        ListNode current = head;
        while (current != null) {
            if (sb.length() > 0) sb.append(' ');
            sb.append(current.val);
            current = current.next;
        }
        return sb.toString();
    }

    static ListNode reverseList(ListNode head) {
        ListNode prev = null;
        ListNode current = head;
        while (current != null) {
            ListNode next = current.next;
            current.next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }

    // ----- 2. Tree traversals — inorder, preorder, postorder -----
    static TreeNode buildSampleTree() {
        //       1
        //      / \
        //     2   3
        //    / \
        //   4   5
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);
        return root;
    }

    static void inorder(TreeNode node, List<Integer> out) {
        if (node == null) return;
        inorder(node.left, out);
        out.add(node.val);
        inorder(node.right, out);
    }

    static void preorder(TreeNode node, List<Integer> out) {
        if (node == null) return;
        out.add(node.val);
        preorder(node.left, out);
        preorder(node.right, out);
    }

    static void postorder(TreeNode node, List<Integer> out) {
        if (node == null) return;
        postorder(node.left, out);
        postorder(node.right, out);
        out.add(node.val);
    }

    static String formatInts(List<Integer> values) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < values.size(); i++) {
            if (i > 0) sb.append(' ');
            sb.append(values.get(i));
        }
        return sb.toString();
    }

    // ----- 3. Graph BFS (Queue) and DFS (Deque as stack) -----
    static List<List<Integer>> buildSampleGraph() {
        // 0 -> 1, 2
        // 1 -> 3
        // 2 -> 4
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < 5; i++) graph.add(new ArrayList<>());
        graph.get(0).add(1);
        graph.get(0).add(2);
        graph.get(1).add(3);
        graph.get(2).add(4);
        return graph;
    }

    static List<Integer> bfs(List<List<Integer>> graph, int start) {
        List<Integer> order = new ArrayList<>();
        boolean[] visited = new boolean[graph.size()];
        Queue<Integer> queue = new ArrayDeque<>();
        queue.offer(start);
        visited[start] = true;
        while (!queue.isEmpty()) {
            int node = queue.poll();
            order.add(node);
            for (int neighbor : graph.get(node)) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    queue.offer(neighbor);
                }
            }
        }
        return order;
    }

    static List<Integer> dfs(List<List<Integer>> graph, int start) {
        List<Integer> order = new ArrayList<>();
        boolean[] visited = new boolean[graph.size()];
        Deque<Integer> stack = new ArrayDeque<>();
        stack.push(start);
        while (!stack.isEmpty()) {
            int node = stack.pop();
            if (visited[node]) continue;
            visited[node] = true;
            order.add(node);
            List<Integer> neighbors = graph.get(node);
            for (int i = neighbors.size() - 1; i >= 0; i--) {
                stack.push(neighbors.get(i));
            }
        }
        return order;
    }

    public static void main(String[] args) {
        ListNode head = buildList(new int[]{1, 2, 3, 4, 5});
        System.out.println("list: " + formatList(head));                    // Output: list: 1 2 3 4 5
        System.out.println("reversed: " + formatList(reverseList(head)));   // Output: reversed: 5 4 3 2 1

        TreeNode root = buildSampleTree();
        List<Integer> in = new ArrayList<>();
        List<Integer> pre = new ArrayList<>();
        List<Integer> post = new ArrayList<>();
        inorder(root, in);
        preorder(root, pre);
        postorder(root, post);
        System.out.println("inorder: " + formatInts(in));                   // Output: inorder: 4 2 5 1 3
        System.out.println("preorder: " + formatInts(pre));                 // Output: preorder: 1 2 4 5 3
        System.out.println("postorder: " + formatInts(post));               // Output: postorder: 4 5 2 3 1

        List<List<Integer>> graph = buildSampleGraph();
        System.out.println("bfs: " + formatInts(bfs(graph, 0)));            // Output: bfs: 0 1 2 3 4
        System.out.println("dfs: " + formatInts(dfs(graph, 0)));            // Output: dfs: 0 1 3 2 4

        // Cross-language note:
        //   Linked lists use pointer fields (next / left+right) — no built-in list type.
        //   Tree traversals are recursive or explicit stack/queue; order names are universal.
        //   BFS uses a FIFO queue; DFS uses a LIFO stack (ArrayDeque push/pop in Java).
        //   Graph adjacency lists are List<List<Integer>> — same idea as dict-of-lists in Python.
    }
}