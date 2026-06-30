// ============================================================
// Topic:  Operators
// Summary: Arithmetic, comparison, logical, increment, ternary.
// Run:     java java/03_operators.java   (Java 11+ single-file launch)
// ============================================================

public class Operators {
    public static void main(String[] args) {
        // ----- 1. Arithmetic -----
        System.out.println(5 + 2);    // 7
        System.out.println(5 - 2);    // 3
        System.out.println(5 * 2);    // 10
        System.out.println(5 / 2);    // 2     int/int truncates (Python 5/2 == 2.5)
        System.out.println(5 / 2.0);  // 2.5   double division
        System.out.println(5 % 2);    // 1
        System.out.println(Math.pow(5, 2)); // 25.0  (Python/TS: 5 ** 2)

        // ----- 2. Comparison -----
        int five = 5, three = 3;
        System.out.println(five == 5);       // true
        System.out.println(five != three);   // true
        // ⚠ For String/object comparison use .equals(), NOT == (== compares references)
        String a = "hi", b = "hi";
        System.out.println(a.equals(b));     // true

        // ----- 3. Logical (symbols, like TS/C#; Python uses and/or/not) -----
        System.out.println(true && false);   // false  (Python: and)
        System.out.println(true || false);   // true   (Python: or)
        System.out.println(!true);           // false  (Python: not)

        // ----- 4. Increment / decrement (Python has NEITHER) -----
        int n = 10;
        n++;                                  // 11   (Python: n += 1)
        n--;                                  // 10
        System.out.println(n);                // Output: 10

        // ----- 5. Augmented assignment -----
        int m = 10;
        m += 5;                               // 15
        m *= 2;                               // 30
        System.out.println(m);                // Output: 30

        // ----- 6. Chained comparison needs && (Python allows 1 < x < 10) -----
        int x = 5;
        System.out.println(1 < x && x < 10);  // true

        // ----- 7. Ternary -----
        String status = x >= 0 ? "non-negative" : "negative";
        System.out.println(status);           // Output: non-negative

        // Cross-language note:
        //   ⚠ For String/object equality use .equals(), NOT == (== compares references).
        //   Logical ops are symbols && || ! (Python uses words and/or/not).
        //   Java has ++ and -- (Python does not). Power = Math.pow (no ** operator).
    }
}
