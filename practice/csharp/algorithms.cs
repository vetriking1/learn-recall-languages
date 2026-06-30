// ============================================================
// Practice: Algorithms
// Summary: linear search, binary search, Fibonacci (iter + rec).
// Run:     dotnet script practice/csharp/algorithms.cs
// ============================================================

using System;
using System.Collections.Generic;
using System.Linq;

// ----- 1. Linear search -> index, or -1 if not found -----
int LinearSearch(int[] arr, int target)
{
    for (int i = 0; i < arr.Length; i++)
        if (arr[i] == target) return i;
    return -1;
}

// ----- 2. Binary search on a SORTED array -> index, or -1 -----
int BinarySearch(int[] arr, int target)
{
    int lo = 0, hi = arr.Length - 1;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}

// ----- 3a. Fibonacci, iterative (N terms) -----
List<int> FibIterative(int n)
{
    var seq = new List<int>();
    int a = 0, b = 1;
    for (int i = 0; i < n; i++)
    {
        seq.Add(a);
        int next = a + b;
        a = b;
        b = next;
    }
    return seq;
}

// ----- 3b. Fibonacci, recursive (nth term) -----
int FibRecursive(int n)
{
    if (n < 2) return n;
    return FibRecursive(n - 1) + FibRecursive(n - 2);
}

Console.WriteLine(LinearSearch(new[] { 4, 2, 7, 1, 9, 3 }, 7));  // Output: 2
Console.WriteLine(LinearSearch(new[] { 4, 2, 7, 1, 9, 3 }, 5));  // Output: -1
Console.WriteLine(BinarySearch(new[] { 1, 3, 5, 7, 9, 11 }, 7)); // Output: 3
Console.WriteLine(BinarySearch(new[] { 1, 3, 5, 7, 9, 11 }, 4)); // Output: -1
Console.WriteLine($"[{string.Join(", ", FibIterative(10))}]");   // [0, 1, 1, 2, 3, 5, 8, 13, 21, 34]
Console.WriteLine($"[{string.Join(", ", Enumerable.Range(0, 10).Select(FibRecursive))}]"); // same
