// ============================================================
// Practice: Numbers
// Summary: prime check, multiplication table, Euclidean GCD.
// Run:     java practice/java/numbers.java   (Java 11+ single-file launch)
// ============================================================

public class NumbersPractice {
    // ----- 1. Is a number prime? -----
    static boolean isPrime(int n) {
        if (n < 2) return false;
        for (long i = 2; i * i <= n; i++)
            if (n % i == 0) return false;
        return true;
    }

    // ----- 2. Multiplication table for n, 1..limit -----
    static void printTable(int n, int limit) {
        for (int i = 1; i <= limit; i++)
            System.out.println(n + " x " + i + " = " + (n * i));
    }

    // ----- 3. GCD via the Euclidean algorithm -----
    static int gcd(int a, int b) {
        while (b != 0) {
            int t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

    public static void main(String[] args) {
        System.out.println(isPrime(7) + " " + isPrime(10)); // true false
        printTable(7, 10);                                   // 7 x 1 = 7 ... 7 x 10 = 70
        System.out.println(gcd(48, 18));                     // 6
    }
}
