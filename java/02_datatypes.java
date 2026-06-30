// ============================================================
// Topic:  Data Types
// Summary: Primitives, wrappers, null, type checking, casting.
// Run:     java java/02_datatypes.java   (Java 11+ single-file launch)
// ============================================================

public class DataTypes {
    public static void main(String[] args) {
        // ----- 1. Core scalar types (primitives) -----
        int anInt = 42;            // int        (Python: int, TS: number)
        double aFloat = 3.14;      // double     (TS: number)
        String aStr = "hello";     // String (an object, not a primitive)
        boolean aBool = true;      // boolean    (Python: True)
        char aChar = 'A';          // single char — SINGLE quotes!
        String nothing = null;     // null reference (Python: None, TS: null)
        System.out.println(anInt + " " + aFloat + " " + aStr + " " + aBool + " " + aChar + " " + nothing);
        // Output: 42 3.14 hello true A null

        // ----- 2. Checking a type (getClass) -----
        System.out.println(((Object) anInt).getClass().getSimpleName()); // Output: Integer
        System.out.println(aStr.getClass().getSimpleName());             // Output: String

        // ----- 3. Wrapper types vs primitives (autoboxing) -----
        Integer boxed = 42;        // wrapper object; `int` is the primitive
        System.out.println(boxed instanceof Integer); // Output: true

        // ----- 4. Conversion / casting -----
        System.out.println(Integer.parseInt("10") + 5);    // str -> int    Output: 15
        System.out.println(Integer.toString(10) + "5");    // int -> str    Output: 105
        System.out.println(Double.parseDouble("3.5"));     // str -> double Output: 3.5
        System.out.println((int) 3.99);                    // double -> int Output: 3

        // ----- 5. Numeric detail (int vs double, like Python/C#) -----
        System.out.println(7 / 2);          // int division     Output: 3
        System.out.println(7 / 2.0);        // double division  Output: 3.5
        System.out.println(Math.pow(2, 10)); // power (no ** op) Output: 1024.0
        System.out.println(10 % 3);         // modulo           Output: 1

        // Cross-language note:
        //   Java splits int vs double (like Python/C#). TS has only `number`.
        //   Primitives (int, double, boolean, char) vs wrapper objects (Integer, Double...).
        //   null is only for object types; primitives can't be null (use wrappers).
    }
}
