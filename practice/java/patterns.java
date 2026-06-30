// ============================================================
// Practice: Patterns
// Summary: right-angled triangle, centered pyramid.
// Run:     java practice/java/patterns.java   (Java 11+ single-file launch)
// ============================================================

public class PatternsPractice {
    // ----- 1. Right-angled triangle of stars -----
    static void rightTriangle(int n) {
        for (int i = 1; i <= n; i++)
            System.out.println("*".repeat(i));
    }

    // ----- 2. Centered pyramid of stars (height h) -----
    static void pyramid(int h) {
        for (int i = 1; i <= h; i++) {
            String spaces = " ".repeat(h - i);
            String stars = "*".repeat(2 * i - 1);
            System.out.println(spaces + stars);
        }
    }

    public static void main(String[] args) {
        System.out.println("Right triangle (N=5):");
        rightTriangle(5);
        // *
        // **
        // ***
        // ****
        // *****

        System.out.println("Pyramid (height=5):");
        pyramid(5);
        //     *
        //    ***
        //   *****
        //  *******
        // *********
    }
}
