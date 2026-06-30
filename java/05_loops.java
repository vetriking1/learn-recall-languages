// ============================================================
// Topic:  Loops
// Summary: C-style for, for-each, while, break/continue, streams.
// Run:     java java/05_loops.java   (Java 11+ single-file launch)
// ============================================================

import java.util.ArrayList;
import java.util.List;

public class Loops {
    public static void main(String[] args) {
        // ----- 1. C-style for (counter loop) -----
        for (int i = 0; i < 3; i++) {
            System.out.print(i + " ");       // Output: 0 1 2
        }
        System.out.println();

        // range with step (Python: range(2, 11, 2))
        for (int i = 2; i < 11; i += 2) {
            System.out.print(i + " ");       // Output: 2 4 6 8 10
        }
        System.out.println();

        // ----- 2. Enhanced for / for-each (Python: for x in coll; TS: for..of) -----
        List<String> fruits = new ArrayList<>(List.of("apple", "banana", "cherry"));
        for (String fruit : fruits) {
            System.out.print(fruit + " ");   // Output: apple banana cherry
        }
        System.out.println();

        // ----- 3. index + value (Python: enumerate) -----
        for (int i = 0; i < fruits.size(); i++) {
            System.out.print(i + ":" + fruits.get(i) + " "); // Output: 0:apple 1:banana 2:cherry
        }
        System.out.println();

        // ----- 4. while loop -----
        int n = 3;
        while (n > 0) {
            System.out.print(n + " ");
            n--;
        }
        System.out.println();                // Output: 3 2 1

        // ----- 5. break and continue -----
        for (int i = 0; i < 10; i++) {
            if (i == 3) continue;            // skip 3
            if (i == 6) break;               // stop at 6
            System.out.print(i + " ");       // Output: 0 1 2 4 5
        }
        System.out.println();

        // ----- 6. Build a list (Python: list comprehension; TS: map) -----
        List<Integer> squares = new ArrayList<>();
        for (int i = 0; i < 5; i++) squares.add(i * i);
        System.out.println(squares);         // Output: [0, 1, 4, 9, 16]

        // Cross-language note:
        //   Enhanced for `for (T x : coll)` == Python `for x in coll` == TS `for..of`.
        //   No range() built-in — use a C-style for or IntStream.range(0, n).
        //   Java has i++; Python uses i += 1.
    }
}
