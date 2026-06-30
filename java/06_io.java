// ============================================================
// Topic:  Console Output & Input
// Summary: println/print, printf, String.format, Scanner.
// Run:     java java/06_io.java   (Java 11+ single-file launch)
// Note:    Reads lines from the keyboard. To pipe input:
//          echo Vetri | java java/06_io.java
//          (PowerShell: "Vetri`n5" | java java/06_io.java)
// ============================================================

import java.util.Scanner;

public class IO {
    public static void main(String[] args) {
        // ----- 1. Basic output -----
        System.out.println("Hello, world");        // Output: Hello, world

        // ----- 2. Print without a trailing newline -----
        System.out.print("no newline ");            // (Python: print(..., end=""))
        System.out.println("next");                 // Output: no newline next

        // ----- 3. Formatted output (printf, C-style) -----
        String name = "Vetri";
        int age = 22;
        System.out.printf("%s is %d%n", name, age); // Output: Vetri is 22
        System.out.printf("%.2f%n", 3.14159);       // Output: 3.14   (%n = newline)

        // ----- 4. String.format builds a string (Python: f-string) -----
        String msg = String.format("%s is %d", name, age);
        System.out.println(msg);                    // Output: Vetri is 22

        // ----- 5. Other output channels -----
        System.err.println("this goes to stderr");  // (Python: file=sys.stderr)

        // ----- 6. Reading input with Scanner -----
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter your name: ");
        String userName = sc.nextLine();
        System.out.println("Hi " + userName + "!");
        // Example (input "Vetri"): Hi Vetri!

        // ----- 7. Converting input to a number -----
        // nextLine() returns a String — parse it (like Python int()).
        System.out.print("Enter a number: ");
        int number = Integer.parseInt(sc.nextLine());
        System.out.println("Doubled: " + number * 2);
        // Example (input "5"): Doubled: 10

        sc.close();

        // Cross-language note:
        //   System.out.println() == Python print() == TS console.log().
        //   printf("%s %d%n", ...) for formatting; %n is the platform newline.
        //   Scanner reads input; nextLine() returns a String (parse for numbers).
    }
}
