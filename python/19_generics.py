# ============================================================
# Topic:  Generics & Type Variables  (FOCUS: TypeVar, Generic, duck typing)
# Summary: Static type hints for generics; runtime stays duck-typed.
# Run:     python python/19_generics.py
#
# KEY DIFFERENCES:
#   Python:  typing.TypeVar / Generic (hints only; erased at runtime)
#   TS:      generics enforced by compiler
#   Rust:    monomorphized generics (zero-cost)
#   Java:    generics with type erasure
#   C++:     templates (compile-time instantiation)
# ============================================================

from typing import Generic, List, Tuple, TypeVar

T = TypeVar("T")
U = TypeVar("U")
Number = TypeVar("Number", int, float)


# ----- 1. Generic swap — TypeVar on a function -----
def swap(a: T, b: T) -> Tuple[T, T]:
    return b, a


# ----- 2. Generic class — Box[T] -----
class Box(Generic[T]):
    def __init__(self, value: T) -> None:
        self._value = value

    def get(self) -> T:
        return self._value


# ----- 3. Bounded TypeVar — only int or float -----
def maximum(a: Number, b: Number) -> Number:
    return a if a > b else b


# ----- 4. Multiple type parameters — pair of different types -----
def make_pair(a: T, b: U) -> Tuple[T, U]:
    return a, b


# ----- 5. List typing — generic collection length -----
def count_items(items: List[T]) -> int:
    return len(items)


# ----- 6. Duck typing — no TypeVar needed at runtime -----
def describe_length(obj) -> int:
    return len(obj)  # works for str, list, tuple, etc.


def main():
    # ----- 1. Generic swap -----
    x, y = swap(1, 2)
    print(f"swap: {x} {y}", flush=True)  # Output: swap: 2 1

    # ----- 2. Generic class Box -----
    box = Box("hello")
    print(f"box: {box.get()}", flush=True)  # Output: box: hello

    # ----- 3. Bounded TypeVar -----
    print(f"max: {maximum(9, 3)}", flush=True)  # Output: max: 9

    # ----- 4. Multiple type parameters -----
    pair = make_pair(1, "two")
    print(f"pair: ({pair[0]}, {pair[1]})", flush=True)  # Output: pair: (1, two)

    # ----- 5. List typing -----
    print(f"items: {count_items([1, 2, 3])}", flush=True)  # Output: items: 3

    # ----- 6. Duck typing (no extra output) -----
    describe_length("abc")


if __name__ == "__main__":
    main()

# Cross-language note:
#   Python generics are for type checkers (mypy, pyright); runtime ignores them.
#   Duck typing ("if it walks like a duck…") is Python's runtime polymorphism.
#   Java/C#/TS enforce generics at compile time; Rust monomorphizes; C++ uses templates.