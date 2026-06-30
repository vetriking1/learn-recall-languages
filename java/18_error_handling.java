// ============================================================
// Topic:  Error Handling  (FOCUS: try/catch, throw, custom Exception, finally)
// Summary: try/catch, throw, custom Exception, finally, nested catch.
// Run:     java java/18_error_handling.java   (Java 11+ single-file launch)
//
// KEY DIFFERENCES:
//   Python:  try/except/raise + custom Exception subclass
//   TS/JS:   try/catch/throw + custom Error subclass
//   Rust:    Result<T,E> + ? operator / panic!
//   Java:    checked + unchecked exceptions; try/catch/finally/throw
//   C++:     try/catch/throw + std::exception
// ============================================================

public class ErrorHandling {

    // ----- Custom exception -----
    static class CustomBadException extends Exception {
        CustomBadException(String message) {
            super(message);
        }
    }

    static int safeDivide(int a, int b) {
        if (b == 0) {
            throw new ArithmeticException("division by zero");
        }
        return a / b;
    }

    static void validate(String value) throws CustomBadException {
        if (!"ok".equals(value)) {
            throw new CustomBadException("invalid");
        }
    }

    static void innerWork() throws Exception {
        throw new Exception("inner failed");
    }

    public static void main(String[] args) {
        // ----- 1. try/catch — normal path -----
        try {
            int result = safeDivide(20, 2);
            System.out.println("result: " + result);              // Output: result: 10
        } catch (ArithmeticException e) {
            System.out.println("caught: " + e.getMessage());
        }

        // ----- 2. throw + catch -----
        try {
            safeDivide(10, 0);
        } catch (ArithmeticException e) {
            System.out.println("caught: " + e.getMessage());      // Output: caught: division by zero
        }

        // ----- 3. Custom exception -----
        try {
            validate("bad");
        } catch (CustomBadException e) {
            System.out.println("CustomBad: " + e.getMessage());   // Output: CustomBad: invalid
        }

        // ----- 4. finally -----
        try {
            safeDivide(1, 0);
        } catch (ArithmeticException e) {
            // handled
        } finally {
            System.out.println("finally ran");                    // Output: finally ran
        }

        // ----- 5. Nested catch -----
        try {
            try {
                innerWork();
            } catch (Exception e) {
                throw new RuntimeException("inner failed", e);
            }
        } catch (RuntimeException e) {
            System.out.println("outer: " + e.getMessage());       // Output: outer: inner failed
        }
    }
}