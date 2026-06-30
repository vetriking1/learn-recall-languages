# ============================================================
# Practice: Arrays
# Summary: max/min, sum/average, in-place reverse, remove dups.
# Run:     python practice/python/arrays.py
# ============================================================

# ----- 1. Max and min of an array -----
def max_min(arr):
    mx = mn = arr[0]
    for x in arr:
        if x > mx: mx = x
        if x < mn: mn = x
    return mx, mn


# ----- 2. Sum and average -----
def sum_avg(arr):
    total = 0
    for x in arr:
        total += x
    return total, total / len(arr)


# ----- 3. Reverse in place (two-pointer swap, no extra array) -----
def reverse_in_place(arr):
    i, j = 0, len(arr) - 1
    while i < j:
        arr[i], arr[j] = arr[j], arr[i]
        i += 1
        j -= 1
    return arr


# ----- 4. Remove duplicates from a SORTED array (in place) -----
def remove_duplicates(arr):
    if not arr:
        return arr
    write = 1
    for read in range(1, len(arr)):
        if arr[read] != arr[write - 1]:
            arr[write] = arr[read]
            write += 1
    return arr[:write]


if __name__ == "__main__":
    print(max_min([3, 7, 1, 9, 2]))          # Output: (9, 1)
    print(sum_avg([10, 20, 30, 40]))         # Output: (100, 25.0)
    print(reverse_in_place([1, 2, 3, 4, 5])) # Output: [5, 4, 3, 2, 1]
    print(remove_duplicates([1, 1, 2, 2, 3, 4, 4, 5])) # Output: [1, 2, 3, 4, 5]
