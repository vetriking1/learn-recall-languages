// ============================================================
// Topic:  Variables
// Summary: var, explicit types, final, naming, static typing.
// Run:     java java/01_variables.java   (Java 11+ single-file launch)
// ============================================================

public class Variables {
    public static void main(String[] args) {
        // ----- 1. var vs explicit type (var since Java 10) -----
        var name = "Vetri";        // inferred String   (Python: name = "Vetri")
        int age = 22;              // explicit type      (TS: let age: number = 22)
        System.out.println(name + " " + age); // Output: Vetri 22

        // ----- 2. final = constant (cannot reassign) -----
        final double PI = 3.14159;
        int score = 10;
        score = 20;                // OK — non-final is mutable
        System.out.println(PI + " " + score); // Output: 3.14159 20
        // PI = 3.0;  // ERROR: cannot assign a value to final variable PI

        // ----- 3. Multiple declaration on one line -----
        int x = 1, y = 2, z = 3;
        System.out.println(x + " " + y + " " + z); // Output: 1 2 3

        // ----- 4. Swapping (no tuple — use a temp variable) -----
        int a = 1, b = 2;
        int temp = a; a = b; b = temp;  // (Python: a, b = b, a)
        System.out.println(a + " " + b); // Output: 2 1

        // ----- 5. Type is fixed once declared (static typing) -----
        String username = "abc";
        int count = 5;
        boolean active = true;
        System.out.println(username + " " + count + " " + active); // Output: abc 5 true

        // ----- 6. Naming: camelCase for variables (like TS; Python uses snake_case) -----
        double totalPrice = 99.5;
        System.out.println(totalPrice); // Output: 99.5

        // Cross-language note:
        //   Java `var` infers type but it stays static (like C# var, TS let, Rust let).
        //   `final` ≈ const (C#/TS); Python has no true const, Rust uses `const`/`let`.
        //   No tuple swap — Java needs a temp var (Python/Rust/C#: (a,b)=(b,a)).
        //   camelCase variables; ClassNames are PascalCase.
    }
}
