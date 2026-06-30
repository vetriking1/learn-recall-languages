// ============================================================
// Topic:  Custom Data Structures  (FOCUS: linked list, binary tree, graph)
// Summary: Pointer-based list, tree traversals, BFS/DFS — built from scratch.
// Run:     g++ -std=c++17 cpp/22_custom_data_structures.cpp -o cpp/22_custom_data_structures && cpp/22_custom_data_structures
//
// KEY DIFFERENCES:
//   Lists:  Python class Node | TS class Node | Java static Node | unique_ptr<Node>
//   Trees:  object refs / pointers | Box<Option<TreeNode>> (Rust) | unique_ptr<TreeNode>
//   Graphs: adjacency list dict/list | vector<vector<int>> + BFS queue / DFS stack
// ============================================================

#include <iostream>
#include <memory>
#include <queue>
#include <vector>

// ----- 1. Singly linked list — unique_ptr owns each node -----
struct ListNode {
    int value;
    std::unique_ptr<ListNode> next;

    explicit ListNode(int v) : value(v), next(nullptr) {}
};

class SinglyLinkedList {
    std::unique_ptr<ListNode> head;

public:
    void push_back(int value) {
        auto* tail = head.get();
        if (!tail) {
            head = std::make_unique<ListNode>(value);
            return;
        }
        while (tail->next) {
            tail = tail->next.get();
        }
        tail->next = std::make_unique<ListNode>(value);
    }

    void reverse() {
        std::unique_ptr<ListNode> prev = nullptr;
        ListNode* current = head.release();
        while (current) {
            ListNode* next = current->next.release();
            current->next = std::move(prev);
            prev.reset(current);
            current = next;
        }
        head = std::move(prev);
    }

    void print(const char* label) const {
        std::cout << label;
        for (ListNode* node = head.get(); node; node = node->next.get()) {
            std::cout << (node == head.get() ? ": " : " ") << node->value;
        }
        std::cout << std::endl;
    }
};

// ----- 2. Binary tree — unique_ptr for left/right children -----
struct TreeNode {
    int value;
    std::unique_ptr<TreeNode> left;
    std::unique_ptr<TreeNode> right;

    explicit TreeNode(int v) : value(v), left(nullptr), right(nullptr) {}
};

class BinaryTree {
    std::unique_ptr<TreeNode> root;

    void inorder(const TreeNode* node, std::vector<int>& out) const {
        if (!node) return;
        inorder(node->left.get(), out);
        out.push_back(node->value);
        inorder(node->right.get(), out);
    }

    void postorder(const TreeNode* node, std::vector<int>& out) const {
        if (!node) return;
        postorder(node->left.get(), out);
        postorder(node->right.get(), out);
        out.push_back(node->value);
    }

    void preorder(const TreeNode* node, std::vector<int>& out) const {
        if (!node) return;
        out.push_back(node->value);
        preorder(node->left.get(), out);
        preorder(node->right.get(), out);
    }

    static void printTraversal(const char* label, const std::vector<int>& values) {
        std::cout << label;
        for (size_t i = 0; i < values.size(); ++i) {
            std::cout << (i == 0 ? ": " : " ") << values[i];
        }
        std::cout << std::endl;
    }

public:
    BinaryTree() {
        // Tree:     1
        //          / \
        //         2   3
        //        / \
        //       4   5
        root = std::make_unique<TreeNode>(1);
        root->left = std::make_unique<TreeNode>(2);
        root->right = std::make_unique<TreeNode>(3);
        root->left->left = std::make_unique<TreeNode>(4);
        root->left->right = std::make_unique<TreeNode>(5);
    }

    void printTraversals() const {
        std::vector<int> values;
        values.clear();
        inorder(root.get(), values);
        printTraversal("inorder", values);
        values.clear();
        postorder(root.get(), values);
        printTraversal("postorder", values);
        values.clear();
        preorder(root.get(), values);
        printTraversal("preorder", values);
    }
};

// ----- 3. Graph — adjacency list + BFS queue / DFS recursion -----
class Graph {
    std::vector<std::vector<int>> adjacency;

    void dfsVisit(int vertex, std::vector<bool>& visited, std::vector<int>& order) const {
        visited[vertex] = true;
        order.push_back(vertex);
        for (int neighbor : adjacency[vertex]) {
            if (!visited[neighbor]) {
                dfsVisit(neighbor, visited, order);
            }
        }
    }

    static void printOrder(const char* label, const std::vector<int>& order) {
        std::cout << label;
        for (size_t i = 0; i < order.size(); ++i) {
            std::cout << (i == 0 ? ": " : " ") << order[i];
        }
        std::cout << std::endl;
    }

public:
    explicit Graph(int vertexCount) : adjacency(vertexCount) {}

    void addEdge(int from, int to) { adjacency[from].push_back(to); }

    void bfs(int start) const {
        std::vector<bool> visited(adjacency.size(), false);
        std::queue<int> frontier;
        std::vector<int> order;

        visited[start] = true;
        frontier.push(start);

        while (!frontier.empty()) {
            int vertex = frontier.front();
            frontier.pop();
            order.push_back(vertex);
            for (int neighbor : adjacency[vertex]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    frontier.push(neighbor);
                }
            }
        }
        printOrder("bfs", order);
    }

    void dfs(int start) const {
        std::vector<bool> visited(adjacency.size(), false);
        std::vector<int> order;
        dfsVisit(start, visited, order);
        printOrder("dfs", order);
    }
};

int main() {
    // ----- 1. Linked list — push, print, reverse -----
    SinglyLinkedList list;
    for (int value : {1, 2, 3, 4, 5}) {
        list.push_back(value);
    }
    list.print("list");
    // Output: list: 1 2 3 4 5
    list.reverse();
    list.print("reversed");
    // Output: reversed: 5 4 3 2 1

    // ----- 2. Binary tree — inorder, postorder, preorder -----
    BinaryTree tree;
    tree.printTraversals();
    // Output: inorder: 4 2 5 1 3
    // Output: postorder: 4 5 2 3 1
    // Output: preorder: 1 2 4 5 3

    // ----- 3. Graph — BFS and DFS from vertex 0 -----
    Graph graph(5);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.bfs(0);
    // Output: bfs: 0 1 2 3 4
    graph.dfs(0);
    // Output: dfs: 0 1 3 2 4

    // Cross-language note:
    //   C++ unique_ptr owns each node — no GC; reverse rewires pointers in place.
    //   Python/TS/Java use object references; Rust uses Box<Option<Node>> for trees.
    //   Graph BFS uses std::queue here; DFS uses recursion (stack implicit in call frame).
    return 0;
}