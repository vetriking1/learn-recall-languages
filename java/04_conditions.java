// ============================================================
// Topic:  Conditions
// Summary: if / else if / else, ternary, switch, switch expression.
// Run:     java java/04_conditions.java   (Java 11+ single-file launch)
// ============================================================

public class Conditions {
    public static void main(String[] args) {
        // ----- 1. if / else if / else (needs ( ) around test and { } block) -----
        int age = 20;
        if (age < 13) {
            System.out.println("child");
        } else if (age < 18) {       // Python: elif
            System.out.println("teen");
        } else {
            System.out.println("adult");
        }
        // Output: adult

        // ----- 2. Ternary (cond ? a : b) -----
        String status = age >= 18 ? "pass" : "fail";
        System.out.println(status);  // Output: pass

        // ----- 3. No implicit truthiness — condition must be boolean -----
        int[] emptyArr = {};
        if (emptyArr.length == 0) {
            System.out.println("empty array has length 0"); // Output: empty array has length 0
        }
        // if (emptyArr) { }  // ERROR: array can't be used as a boolean
        String greeting = "hello";
        if (!greeting.isEmpty()) {
            System.out.println("non-empty string"); // Output: non-empty string
        }

        // ----- 4. Combining conditions -----
        int temp = 25;
        if (temp > 20 && temp < 30) {
            System.out.println("comfortable"); // Output: comfortable
        }

        // ----- 5. Classic switch (with break — fall-through otherwise!) -----
        String command = "start";
        switch (command) {
            case "start":
                System.out.println("starting"); // Output: starting
                break;                            // ⚠ don't forget break
            case "stop":
                System.out.println("stopping");
                break;
            default:
                System.out.println("unknown");
        }

        // ----- 6. switch expression (Java 14+, arrow form, no break) -----
        int day = 3;
        String kind = switch (day) {
            case 1, 7 -> "weekend";
            case 2, 3, 4, 5, 6 -> "weekday";
            default -> "invalid";
        };
        System.out.println(kind); // Output: weekday

        // Cross-language note:
        //   Java needs an explicit boolean in if (no truthiness — like C#/Rust).
        //   Classic switch falls through without break; switch expression (->) does not.
        //   Ternary order: cond ? a : b  (Python: a if cond else b).
    }
}
