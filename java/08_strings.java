// ============================================================
// Topic:  Strings  (FOCUS: methods & operations)
// Summary: length, charAt, substring, case, search, split/join, format.
// Run:     java java/08_strings.java   (Java 11+ single-file launch)
//
// KEY DIFFERENCE the user cares about:
//   Java: s.length()  (a METHOD)   |   JS/TS: s.length (a property)
//   Java: s.toLowerCase()          |   Python: s.lower()
//   ⚠ Compare strings with .equals(), not == (see 03_operators).
// ============================================================

import java.util.Arrays;

public class Strings {
    public static void main(String[] args) {
        String s = "Hello, World";

        // ----- 1. Length (a METHOD with (), unlike the JS property) -----
        System.out.println(s.length());               // 12   (Python: len(s); TS: s.length)

        // ----- 2. Char at index -----
        System.out.println(s.charAt(0));               // H    (Python: s[0])
        System.out.println(s.charAt(s.length() - 1));  // d    (Python: s[-1]; no negative index)

        // ----- 3. Substring (Python: s[start:stop]) -----
        System.out.println(s.substring(0, 5));         // Hello
        System.out.println(s.substring(7));            // World
        System.out.println(new StringBuilder(s).reverse()); // dlroW ,olleH (Python: s[::-1])

        // ----- 4. Case methods -----
        System.out.println(s.toLowerCase());           // hello, world  (Python: s.lower())
        System.out.println(s.toUpperCase());           // HELLO, WORLD  (Python: s.upper())

        // ----- 5. Search / test -----
        System.out.println(s.indexOf("World"));        // 7    (-1 if missing)
        System.out.println(s.contains("World"));       // true (Python: "World" in s)
        System.out.println(s.startsWith("Hello"));     // true
        System.out.println(s.endsWith("World"));       // true

        // ----- 6. Modify (strings are IMMUTABLE; methods return NEW strings) -----
        System.out.println(s.replace("World", "Java")); // Hello, Java
        System.out.println("  pad  ".strip());         // pad   (Java 11+; Python: s.strip())
        System.out.println(Arrays.toString("a,b,c".split(","))); // [a, b, c]
        System.out.println(String.join("-", "a", "b", "c"));     // a-b-c  (Python: "-".join(...))
        System.out.println("ha".repeat(3));            // hahaha (Java 11+; Python: "ha" * 3)

        // ----- 7. Formatting / interpolation (no f-strings — use format) -----
        String name = "Vetri";
        System.out.println(String.format("%s is %d", name, 22)); // Vetri is 22

        // ----- 8. char <-> code -----
        System.out.println((int) 'A');                 // 65  (Python: ord("A"))
        System.out.println((char) 66);                 // B   (Python: chr(66))

        // Cross-language note:
        //   length() is a METHOD (parens) — unlike JS's s.length property.
        //   Strings immutable; use StringBuilder to build/reverse efficiently.
        //   No slice operator — use substring(start, end). No negative indices.
        //   Compare content with .equals(), never == (== compares references).
    }
}
