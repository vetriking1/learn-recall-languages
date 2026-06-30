// ============================================================
// Practice: Algorithms
// Summary: linear search, binary search, Fibonacci (iter + rec).
// Run:     java practice/java/algorithms.java   (Java 11+ single-file launch)
// ============================================================

import java.util.ArrayList;
import java.util.List;

public class AlgorithmsPractice {
    // ----- 1. Linear search -> index, or -1 if not found -----
    static int linearSearch(int[] arr, int target) {
        for (int i = 0; i < arr.length; i++)
            if (arr[i] == target) return i;
        return -1;
    }

    // ----- 2. Binary search on a SORTED array -> index, or -1 -----
    static int binarySearch(int[] arr, int target) {
        int lo = 0, hi = arr.length - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (arr[mid] == target) return mid;
            else if (arr[mid] < target) lo = mid + 1;
            else hi = mid - 1;
        }
        return -1;
    }

    // ----- 3a. Fibonacci, iterative (N terms) -----
    static List<Long> fibIterative(int n) {
        List<Long> seq = new ArrayList<>();
        long a = 0, b = 1;
        for (int i = 0; i < n; i++) {
            seq.add(a);
            long next = a + b;
            a = b;
            b = next;
        }
        return seq;
    }

    // ----- 3b. Fibonacci, recursive (nth term) -----
    static long fibRecursive(int n) {
        if (n < 2) return n;
        return fibRecursive(n - 1) + fibRecursive(n - 2);
    }

    public static void main(String[] args) {
        System.out.println(linearSearch(new int[]{4, 2, 7, 1, 9, 3}, 7));  // 2
        System.out.println(linearSearch(new int[]{4, 2, 7, 1, 9, 3}, 5));  // -1
        System.out.println(binarySearch(new int[]{1, 3, 5, 7, 9, 11}, 7)); // 3
        System.out.println(binarySearch(new int[]{1, 3, 5, 7, 9, 11}, 4)); // -1
        System.out.println(fibIterative(10)); // [0, 1, 1, 2, 3, 5, 8, 13, 21, 34]
        List<Long> rec = new ArrayList<>();
        for (int i = 0; i < 10; i++) rec.add(fibRecursive(i));
        System.out.println(rec);              // same
    }
}
