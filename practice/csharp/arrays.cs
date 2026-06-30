// ============================================================
// Practice: Arrays
// Summary: max/min, sum/average, in-place reverse, remove dups.
// Run:     dotnet script practice/csharp/arrays.cs
// ============================================================

using System;
using System.Collections.Generic;

// ----- 1. Max and min of an array -----
(int, int) MaxMin(int[] arr)
{
    int mx = arr[0], mn = arr[0];
    foreach (var x in arr)
    {
        if (x > mx) mx = x;
        if (x < mn) mn = x;
    }
    return (mx, mn);
}

// ----- 2. Sum and average -----
(int, double) SumAvg(int[] arr)
{
    int total = 0;
    foreach (var x in arr) total += x;
    return (total, (double)total / arr.Length);
}

// ----- 3. Reverse in place (two-pointer swap, no extra array) -----
int[] ReverseInPlace(int[] arr)
{
    int i = 0, j = arr.Length - 1;
    while (i < j)
    {
        (arr[i], arr[j]) = (arr[j], arr[i]);
        i++;
        j--;
    }
    return arr;
}

// ----- 4. Remove duplicates from a SORTED array -----
List<int> RemoveDuplicates(int[] arr)
{
    var result = new List<int>();
    foreach (var x in arr)
    {
        if (result.Count == 0 || result[result.Count - 1] != x)
            result.Add(x);
    }
    return result;
}

var (mx, mn) = MaxMin(new[] { 3, 7, 1, 9, 2 });
Console.WriteLine($"({mx}, {mn})");                  // Output: (9, 1)
var (sum, avg) = SumAvg(new[] { 10, 20, 30, 40 });
Console.WriteLine($"({sum}, {avg})");                // Output: (100, 25)
Console.WriteLine($"[{string.Join(", ", ReverseInPlace(new[] { 1, 2, 3, 4, 5 }))}]");      // [5, 4, 3, 2, 1]
Console.WriteLine($"[{string.Join(", ", RemoveDuplicates(new[] { 1, 1, 2, 2, 3, 4, 4, 5 }))}]"); // [1, 2, 3, 4, 5]
