// ============================================================
// Practice: Arrays
// Summary: max/min, sum/average, in-place reverse, remove dups.
// Run:     java practice/java/arrays.java   (Java 11+ single-file launch)
// ============================================================

import java.util.ArrayList;
import java.util.List;

public class ArraysPractice {
    // ----- 1. Max and min of an array -----
    static int[] maxMin(int[] arr) {
        int mx = arr[0], mn = arr[0];
        for (int x : arr) {
            if (x > mx) mx = x;
            if (x < mn) mn = x;
        }
        return new int[]{mx, mn};
    }

    // ----- 2. Sum and average -----
    static double[] sumAvg(int[] arr) {
        int total = 0;
        for (int x : arr) total += x;
        return new double[]{total, (double) total / arr.length};
    }

    // ----- 3. Reverse in place (two-pointer swap) -----
    static int[] reverseInPlace(int[] arr) {
        int i = 0, j = arr.length - 1;
        while (i < j) {
            int t = arr[i]; arr[i] = arr[j]; arr[j] = t;
            i++;
            j--;
        }
        return arr;
    }

    // ----- 4. Remove duplicates from a SORTED array -----
    static List<Integer> removeDuplicates(int[] arr) {
        List<Integer> result = new ArrayList<>();
        for (int x : arr) {
            if (result.isEmpty() || result.get(result.size() - 1) != x) result.add(x);
        }
        return result;
    }

    public static void main(String[] args) {
        int[] mm = maxMin(new int[]{3, 7, 1, 9, 2});
        System.out.println("(" + mm[0] + ", " + mm[1] + ")");          // (9, 1)
        double[] sa = sumAvg(new int[]{10, 20, 30, 40});
        System.out.println("(" + (int) sa[0] + ", " + sa[1] + ")");    // (100, 25.0)
        System.out.println(java.util.Arrays.toString(reverseInPlace(new int[]{1, 2, 3, 4, 5}))); // [5, 4, 3, 2, 1]
        System.out.println(removeDuplicates(new int[]{1, 1, 2, 2, 3, 4, 4, 5})); // [1, 2, 3, 4, 5]
    }
}
