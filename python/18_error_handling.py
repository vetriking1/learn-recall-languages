# ============================================================
# Topic:  Error Handling  (FOCUS: try/except, raise, finally, propagate)
# Summary: Catch exceptions, raise your own, clean up with finally.
# Run:     python python/18_error_handling.py
#
# KEY DIFFERENCES:
#   Python:  try/except/else/finally + raise (stdlib)
#   TS/JS:   try/catch/finally + throw
#   Rust:    Result<T,E> + ? operator | panic!
#   Java:    try/catch/finally + throw
#   C++:     try/catch + throw
# ============================================================


# ----- 1. try/except — catch and recover -----
def safe_divide(a, b):
    try:
        return a / b
    except ZeroDivisionError:
        print("caught: division by zero", flush=True)  # Output: caught: division by zero
        return None


# ----- 2. raise — signal an error -----
def validate_positive(n):
    if n < 0:
        raise ValueError("must be positive")
    return n


# ----- 3. Custom Exception class -----
class CustomBad(Exception):
    """Raised when input fails a custom rule."""


def check_valid(label):
    if label == "invalid":
        raise CustomBad("invalid")


# ----- 4. finally — always runs -----
def with_finally():
    try:
        raise RuntimeError("trigger")
    except RuntimeError:
        pass
    finally:
        print("finally ran", flush=True)  # Output: finally ran


# ----- 5. Re-raise / propagate — outer handler catches inner -----
def inner_fail():
    raise ValueError("inner failed")


def outer_catch():
    try:
        inner_fail()
    except ValueError as e:
        print(f"outer: {e}", flush=True)  # Output: outer: inner failed


# ----- 6. else clause — runs only when try succeeds -----
def parse_int(text):
    try:
        value = int(text)
    except ValueError:
        return None
    else:
        return value * 2  # no exception → else block runs


def main():
    # ----- 1. try/except -----
    result = safe_divide(20, 2)
    print(f"result: {int(result)}", flush=True)  # Output: result: 10
    safe_divide(10, 0)

    # ----- 2. raise (used by validate_positive; no extra output) -----
    validate_positive(5)

    # ----- 3. Custom Exception -----
    try:
        check_valid("invalid")
    except CustomBad as e:
        print(f"CustomBad: {e}", flush=True)  # Output: CustomBad: invalid

    # ----- 4. finally -----
    with_finally()

    # ----- 5. Re-raise / propagate -----
    outer_catch()

    # ----- 6. else clause (demonstrated; no extra output) -----
    parse_int("7")


if __name__ == "__main__":
    main()

# Cross-language note:
#   Python's bare raise re-raises the current exception; use `raise X from Y` to chain causes.
#   else runs only when try completes without exception; finally always runs.
#   Custom exceptions subclass Exception — like Java checked/unchecked or TS custom Error classes.
#   Rust prefers Result over exceptions; C++ and Java use similar try/catch patterns.