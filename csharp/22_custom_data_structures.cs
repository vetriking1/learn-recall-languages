// ============================================================
// Topic:  Custom Data Structures  (FOCUS: linked list, tree, graph)
// Summary: Hand-rolled ListNode, TreeNode; list reverse; tree traversals;
//          graph BFS (Queue) and DFS (recursion).
// Run:     dotnet script csharp/22_custom_data_structures.cs
//
// KEY DIFFERENCES:
//   Python:  class Node; dict[int, list[int]] adjacency
//   TS/JS:   { val, next } / { val, left, right }; Map for graph
//   Rust:    Box<Node> or Rc<RefCell<Node>>; HashMap<Vec<i32>>
//   Java:    static nested classes; List<List<Integer>> adjacency
//   C++:     struct Node*; std::unordered_map<int, vector<int>>
// ============================================================

#nullable enable

using System;
using System.Collections.Generic;

// ----- ListNode — singly linked list cell -----
class ListNode
{
    public int Val;
    public ListNode? Next;

    public ListNode(int val, ListNode? next = null)
    {
        Val = val;
        Next = next;
    }
}

// ----- TreeNode — binary tree cell -----
class TreeNode
{
    public int Val;
    public TreeNode? Left;
    public TreeNode? Right;

    public TreeNode(int val, TreeNode? left = null, TreeNode? right = null)
    {
        Val = val;
        Left = left;
        Right = right;
    }
}

// ----- 1. Linked list — build, traverse, reverse -----
ListNode? BuildLinkedList(int[] values)
{
    if (values.Length == 0) return null;
    var head = new ListNode(values[0]);
    var current = head;
    for (int i = 1; i < values.Length; i++)
    {
        current.Next = new ListNode(values[i]);
        current = current.Next;
    }
    return head;
}

List<int> TraverseList(ListNode? head)
{
    var result = new List<int>();
    while (head != null)
    {
        result.Add(head.Val);
        head = head.Next;
    }
    return result;
}

ListNode? ReverseList(ListNode? head)
{
    ListNode? prev = null;
    var current = head;
    while (current != null)
    {
        var next = current.Next;
        current.Next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

// ----- 2. Tree traversals — inorder, preorder, postorder -----
TreeNode BuildSampleTree() =>
    new TreeNode(
        1,
        new TreeNode(2, new TreeNode(4), new TreeNode(5)),
        new TreeNode(3));

void Inorder(TreeNode? node, List<int> outList)
{
    if (node == null) return;
    Inorder(node.Left, outList);
    outList.Add(node.Val);
    Inorder(node.Right, outList);
}

void Preorder(TreeNode? node, List<int> outList)
{
    if (node == null) return;
    outList.Add(node.Val);
    Preorder(node.Left, outList);
    Preorder(node.Right, outList);
}

void Postorder(TreeNode? node, List<int> outList)
{
    if (node == null) return;
    Postorder(node.Left, outList);
    Postorder(node.Right, outList);
    outList.Add(node.Val);
}

// ----- 3. Graph BFS (Queue) and DFS (recursion) -----
Dictionary<int, List<int>> BuildSampleGraph() => new()
{
    [0] = new List<int> { 1, 2 },
    [1] = new List<int> { 0, 3 },
    [2] = new List<int> { 0, 4 },
    [3] = new List<int> { 1 },
    [4] = new List<int> { 2 },
};

List<int> Bfs(Dictionary<int, List<int>> graph, int start)
{
    var visited = new HashSet<int>();
    var queue = new Queue<int>();
    queue.Enqueue(start);
    var order = new List<int>();
    while (queue.Count > 0)
    {
        int node = queue.Dequeue();
        if (visited.Contains(node)) continue;
        visited.Add(node);
        order.Add(node);
        foreach (int neighbor in graph[node])
        {
            if (!visited.Contains(neighbor))
                queue.Enqueue(neighbor);
        }
    }
    return order;
}

List<int> Dfs(Dictionary<int, List<int>> graph, int start)
{
    var visited = new HashSet<int>();
    var order = new List<int>();

    void Visit(int node)
    {
        visited.Add(node);
        order.Add(node);
        foreach (int neighbor in graph[node])
        {
            if (!visited.Contains(neighbor))
                Visit(neighbor);
        }
    }

    Visit(start);
    return order;
}

string FormatInts(IEnumerable<int> values) => string.Join(" ", values);

// ----- Demo output -----
var head = BuildLinkedList(new[] { 1, 2, 3, 4, 5 });
Console.WriteLine($"list: {FormatInts(TraverseList(head))}");           // list: 1 2 3 4 5
Console.WriteLine($"reversed: {FormatInts(TraverseList(ReverseList(head)))}"); // reversed: 5 4 3 2 1

var tree = BuildSampleTree();
var inOrder = new List<int>();
var preOrder = new List<int>();
var postOrder = new List<int>();
Inorder(tree, inOrder);
Preorder(tree, preOrder);
Postorder(tree, postOrder);
Console.WriteLine($"inorder: {FormatInts(inOrder)}");                   // inorder: 4 2 5 1 3
Console.WriteLine($"preorder: {FormatInts(preOrder)}");                 // preorder: 1 2 4 5 3
Console.WriteLine($"postorder: {FormatInts(postOrder)}");               // postorder: 4 5 2 3 1

var graph = BuildSampleGraph();
Console.WriteLine($"bfs: {FormatInts(Bfs(graph, 0))}");                 // bfs: 0 1 2 3 4
Console.WriteLine($"dfs: {FormatInts(Dfs(graph, 0))}");                   // dfs: 0 1 3 2 4

// Cross-language note:
//   Linked lists use pointer fields (Next / Left+Right) — no built-in list type in C++/Rust/Java.
//   Tree traversals are recursive or explicit stack/queue; order names are universal.
//   BFS uses a FIFO queue; DFS uses recursion or a LIFO stack.
//   Graph adjacency is Dictionary<int, List<int>> — same idea as dict-of-lists in Python.