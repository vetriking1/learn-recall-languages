// ============================================================
// Topic:  Error Handling  (FOCUS: try/catch, throw, custom Error, finally)
// Summary: try/catch, throw, custom Error class, finally, rethrow wrapped, unknown in catch.
// Run:     npx ts-node typescript/18_error_handling.ts
//
// KEY DIFFERENCES:
//   Python:  try/except/raise + custom Exception subclass
//   TS/JS:   try/catch/throw + custom Error subclass; catch (e: unknown)
//   Rust:    Result<T,E> + ? operator / panic!
//   Java:    checked + unchecked exceptions; try/catch/finally/throw
//   C++:     try/catch/throw + std::exception
// ============================================================

// ----- Custom Error class -----
class CustomBadError extends Error {
  constructor(message: string) {
    super(message);
    this.name = "CustomBadError";
  }
}

function safeDivide(a: number, b: number): number {
  if (b === 0) {
    throw new Error("division by zero");
  }
  return a / b;
}

function validate(value: string): void {
  if (value !== "ok") {
    throw new CustomBadError("invalid");
  }
}

function innerWork(): void {
  throw new Error("inner failed");
}

// ----- 1. try/catch — normal path -----
try {
  const result = safeDivide(20, 2);
  console.log(`result: ${result}`); // Output: result: 10
} catch (e: unknown) {
  const msg = e instanceof Error ? e.message : String(e);
  console.log(`caught: ${msg}`);
}

// ----- 2. throw + catch (unknown in catch) -----
try {
  safeDivide(10, 0);
} catch (e: unknown) {
  if (e instanceof Error) {
    console.log(`caught: ${e.message}`); // Output: caught: division by zero
  }
}

// ----- 3. Custom Error -----
try {
  validate("bad");
} catch (e: unknown) {
  if (e instanceof CustomBadError) {
    console.log(`CustomBad: ${e.message}`); // Output: CustomBad: invalid
  }
}

// ----- 4. finally -----
try {
  safeDivide(1, 0);
} catch (e: unknown) {
  // handled
} finally {
  console.log("finally ran"); // Output: finally ran
}

// ----- 5. Rethrow wrapped + outer catch -----
try {
  try {
    innerWork();
  } catch (e: unknown) {
    const msg = e instanceof Error ? e.message : "unknown";
    throw new Error(msg);
  }
} catch (e: unknown) {
  if (e instanceof Error) {
    console.log(`outer: ${e.message}`); // Output: outer: inner failed
  }
}

// Cross-language note:
//   TS catch (e: unknown) forces narrowing before using e — safer than catch (e: any).
//   CustomBadError extends Error like Python's class CustomBad(Exception).
//   Rethrowing wrapped: throw new Error(msg) preserves message for outer handler.