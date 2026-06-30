# ============================================================
# Practice: Algorithms
# Summary: linear search, binary search, Fibonacci (iter + rec).
# Run:     python practice/python/algorithms.py
# ============================================================

# ----- 1. Linear search -> index, or -1 if not found -----
def linear_search(arr, target):
    for i in range(len(arr)):
        if arr[i] == target:
            return i
    return -1


# ----- 2. Binary search on a SORTED array -> index, or -1 -----
def binary_search(arr, target):
    lo, hi = 0, len(arr) - 1
    while lo <= hi:
        mid = (lo + hi) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            lo = mid + 1
        else:
            hi = mid - 1
    return -1


# ----- 3a. Fibonacci, iterative (N terms) -----
def fib_iterative(n):
    seq = []
    a, b = 0, 1
    for _ in range(n):
        seq.append(a)
        a, b = b, a + b
    return seq


# ----- 3b. Fibonacci, recursive (nth term) -----
def fib_recursive(n):
    if n < 2:
        return n
    return fib_recursive(n - 1) + fib_recursive(n - 2)


if __name__ == "__main__":
    print(linear_search([4, 2, 7, 1, 9, 3], 7))   # Output: 2
    print(linear_search([4, 2, 7, 1, 9, 3], 5))   # Output: -1
    print(binary_search([1, 3, 5, 7, 9, 11], 7))  # Output: 3
    print(binary_search([1, 3, 5, 7, 9, 11], 4))  # Output: -1
    print(fib_iterative(10))                       # Output: [0, 1, 1, 2, 3, 5, 8, 13, 21, 34]
    print([fib_recursive(i) for i in range(10)])   # Output: [0, 1, 1, 2, 3, 5, 8, 13, 21, 34]
