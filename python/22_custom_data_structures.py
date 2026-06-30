# ============================================================
# Topic:  Custom Data Structures  (FOCUS: linked list, tree, graph)
# Summary: Hand-rolled nodes — traverse, reverse, tree walks, BFS/DFS.
# Run:     python python/22_custom_data_structures.py
#
# KEY DIFFERENCES:
#   Linked list:  class Node { next } | struct ListNode | Option<Box<Node>>
#   Binary tree:  left/right pointers | TreeNode | Option<Box<TreeNode>>
#   Graph BFS:    deque/queue | Queue | VecDeque | LinkedList (Java)
#   Graph DFS:    recursion or explicit stack | same pattern all langs
# ============================================================

from collections import deque


# ----- Shared node types -----
class ListNode:
    def __init__(self, val: int, next_node: "ListNode | None" = None) -> None:
        self.val = val
        self.next = next_node


class TreeNode:
    def __init__(
        self,
        val: int,
        left: "TreeNode | None" = None,
        right: "TreeNode | None" = None,
    ) -> None:
        self.val = val
        self.left = left
        self.right = right


def build_linked_list(values: list[int]) -> ListNode | None:
    """Build 1→2→3→4→5 from a value list."""
    if not values:
        return None
    head = ListNode(values[0])
    current = head
    for val in values[1:]:
        current.next = ListNode(val)
        current = current.next
    return head


def traverse_list(head: ListNode | None) -> list[int]:
    result: list[int] = []
    while head:
        result.append(head.val)
        head = head.next
    return result


def reverse_list(head: ListNode | None) -> ListNode | None:
    prev: ListNode | None = None
    current = head
    while current:
        nxt = current.next
        current.next = prev
        prev = current
        current = nxt
    return prev


def build_sample_tree() -> TreeNode:
    """Tree: root 1, left 2 (children 4, 5), right 3."""
    return TreeNode(
        1,
        TreeNode(2, TreeNode(4), TreeNode(5)),
        TreeNode(3),
    )


def inorder(node: TreeNode | None) -> list[int]:
    if not node:
        return []
    return inorder(node.left) + [node.val] + inorder(node.right)


def preorder(node: TreeNode | None) -> list[int]:
    if not node:
        return []
    return [node.val] + preorder(node.left) + preorder(node.right)


def postorder(node: TreeNode | None) -> list[int]:
    if not node:
        return []
    return postorder(node.left) + postorder(node.right) + [node.val]


def build_sample_graph() -> dict[int, list[int]]:
    """Undirected graph; neighbors sorted ascending."""
    return {
        0: [1, 2],
        1: [0, 3],
        2: [0, 4],
        3: [1],
        4: [2],
    }


def bfs(graph: dict[int, list[int]], start: int) -> list[int]:
    visited: set[int] = set()
    queue: deque[int] = deque([start])
    order: list[int] = []
    while queue:
        node = queue.popleft()
        if node in visited:
            continue
        visited.add(node)
        order.append(node)
        for neighbor in graph[node]:
            if neighbor not in visited:
                queue.append(neighbor)
    return order


def dfs(graph: dict[int, list[int]], start: int) -> list[int]:
    visited: set[int] = set()
    order: list[int] = []

    def visit(node: int) -> None:
        visited.add(node)
        order.append(node)
        for neighbor in graph[node]:
            if neighbor not in visited:
                visit(neighbor)

    visit(start)
    return order


def main() -> None:
    # ----- 1. Linked list build + traverse -----
    head = build_linked_list([1, 2, 3, 4, 5])
    print(f"list: {' '.join(str(v) for v in traverse_list(head))}", flush=True)
    # Output: list: 1 2 3 4 5

    # ----- 2. Reverse linked list -----
    reversed_head = reverse_list(head)
    print(
        f"reversed: {' '.join(str(v) for v in traverse_list(reversed_head))}",
        flush=True,
    )
    # Output: reversed: 5 4 3 2 1

    # ----- 3. Inorder traversal -----
    tree = build_sample_tree()
    print(f"inorder: {' '.join(str(v) for v in inorder(tree))}", flush=True)
    # Output: inorder: 4 2 5 1 3

    # ----- 4. Preorder traversal -----
    print(f"preorder: {' '.join(str(v) for v in preorder(tree))}", flush=True)
    # Output: preorder: 1 2 4 5 3

    # ----- 5. Postorder traversal -----
    print(f"postorder: {' '.join(str(v) for v in postorder(tree))}", flush=True)
    # Output: postorder: 4 5 2 3 1

    # ----- 6. Graph BFS + DFS -----
    graph = build_sample_graph()
    print(f"bfs: {' '.join(str(v) for v in bfs(graph, 0))}", flush=True)
    # Output: bfs: 0 1 2 3 4
    print(f"dfs: {' '.join(str(v) for v in dfs(graph, 0))}", flush=True)
    # Output: dfs: 0 1 3 2 4


if __name__ == "__main__":
    main()

# Cross-language note:
#   Linked lists use pointer/next fields — no built-in list type in C++/Rust/Java.
#   Tree traversals are identical recursion patterns; iterative uses an explicit stack.
#   BFS needs a queue (deque); DFS uses recursion or a stack — neighbor order matters.
#   Graph adjacency lists map node → sorted neighbor list for deterministic output.