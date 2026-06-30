// ============================================================
// Topic:  Functions
// Summary: Static methods, overloading, varargs, lambdas, returns.
// Run:     java java/07_functions.java   (Java 11+ single-file launch)
// ============================================================

import java.util.function.IntBinaryOperator;
import java.util.function.IntUnaryOperator;

public class Functions {
    // ----- 1. Basic method (typed params + return) -----
    static String greet(String name) {
        return "Hello, " + name;
    }

    // ----- 2. Default params — Java has none; use OVERLOADING -----
    static int power(int base) { return power(base, 2); } // exp defaults to 2
    static int power(int base, int exp) {
        return (int) Math.pow(base, exp);
    }

    // ----- 3. Varargs (Python: *args; TS: ...rest) -----
    static int total(int... numbers) {
        int sum = 0;
        for (int n : numbers) sum += n;
        return sum;
    }

    // ----- 4. Returning multiple values — use an array (no native tuple) -----
    static int[] minMax(int[] nums) {
        int min = nums[0], max = nums[0];
        for (int n : nums) {
            if (n < min) min = n;
            if (n > max) max = n;
        }
        return new int[]{min, max};
    }

    public static void main(String[] args) {
        System.out.println(greet("Vetri"));        // Output: Hello, Vetri

        // ----- 5. Lambda (Java 8+) — needs a functional interface type -----
        IntBinaryOperator add = (a, b) -> a + b;
        System.out.println(add.applyAsInt(2, 3));  // Output: 5
        IntUnaryOperator square = x -> x * x;
        System.out.println(square.applyAsInt(5));  // Output: 25

        // ----- 6. Overloaded "default" -----
        System.out.println(power(5));              // Output: 25  (exp defaults to 2)
        System.out.println(power(5, 3));           // Output: 125

        // ----- 7. Varargs call -----
        System.out.println(total(1, 2, 3, 4));     // Output: 10

        // ----- 8. Multiple return via array -----
        int[] mm = minMax(new int[]{4, 1, 9, 2});
        System.out.println(mm[0] + " " + mm[1]);   // Output: 1 9

        // Cross-language note:
        //   Java methods live in a class; mark `static` to call without an instance.
        //   No default params — use method overloading instead.
        //   Lambdas need a functional interface (Function, IntBinaryOperator, ...).
        //   Multiple returns: return an array/record/object (no native tuple).
    }
}
