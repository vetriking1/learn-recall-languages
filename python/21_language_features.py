# ============================================================
# Topic:  Language-Specific Features  (FOCUS: Python-only idioms)
# Summary: Comprehensions, decorators, f-strings, *args/**kwargs, with, yield.
# Run:     python python/21_language_features.py
#
# KEY DIFFERENCES:
#   Python:  list comps, @decorator, f-strings, *args/**kwargs, with, yield
#   TS/JS:   map/filter, HOF wrappers, template literals, rest/spread, try/finally, generators
#   Rust:    iterators/map, attributes/macros, format!, variadics (limited), Drop trait, iterators
#   Java:    streams, annotations, String.format, varargs, try-with-resources, Stream.iterate
#   C++:     range-for/algorithms, attributes, fmt/ostringstream, variadic templates, RAII, coroutines
# ============================================================


# ----- 1. List comprehension — build a list in one expression -----
def demo_list_comprehension():
    doubled = [x * 2 for x in range(3)]
    print(f"comp: {doubled}", flush=True)  # Output: comp: [0, 2, 4]


# ----- 2. Decorator — wrap a function to change its behavior -----
def shout(fn):
    def wrapper():
        return fn().upper()

    return wrapper


@shout
def greet():
    return "hello"


def demo_decorator():
    print(f"decorated: {greet()}", flush=True)  # Output: decorated: HELLO


# ----- 3. f-string — embed expressions inside a string literal -----
def demo_fstring():
    name = "Vetri"
    score = 90
    print(f"fmt: name={name} score={score}", flush=True)  # Output: fmt: name=Vetri score=90


# ----- 4. *args / **kwargs — variable positional and keyword arguments -----
def demo_args_kwargs(a, b, *args, **kwargs):
    kw_val = kwargs.get("kw", "")
    print(f"args: {a} {b} kw={kw_val}", flush=True)  # Output: args: 1 2 kw=ok


# ----- 5. with statement — context manager for setup/teardown -----
class OkContext:
    def __enter__(self):
        return self

    def __exit__(self, exc_type, exc_val, exc_tb):
        return False


def demo_with():
    with OkContext():
        print("with: ok", flush=True)  # Output: with: ok


# ----- 6. Generator yield — lazy sequence via yield -----
def count_up():
    for i in range(1, 4):
        yield i


def demo_generator():
    values = " ".join(str(n) for n in count_up())
    print(f"gen: {values}", flush=True)  # Output: gen: 1 2 3


def main():
    # ----- 1. List comprehension -----
    demo_list_comprehension()

    # ----- 2. Decorator -----
    demo_decorator()

    # ----- 3. f-string -----
    demo_fstring()

    # ----- 4. *args / **kwargs -----
    demo_args_kwargs(1, 2, kw="ok")

    # ----- 5. with statement -----
    demo_with()

    # ----- 6. Generator yield -----
    demo_generator()


if __name__ == "__main__":
    main()

# Cross-language note:
#   List comprehensions replace manual loops + append (TS: map/filter; Java: streams).
#   Decorators are higher-order functions applied with @syntax (Java: annotations differ).
#   f-strings are inline interpolation (TS: template literals; Java: String.format).
#   *args/**kwargs collect extra arguments (TS: rest/spread; Java: varargs + Map).
#   with calls __enter__/__exit__ (Java: try-with-resources; C++: RAII).
#   yield makes a generator — lazy, memory-efficient iteration (TS/JS: function*).