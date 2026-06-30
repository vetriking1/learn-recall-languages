# ============================================================
# Topic:  Abstraction
# Summary: An abstract base defines a contract; it can't be instantiated.
# Run:     python python/14_abstraction.py
# ============================================================

from abc import ABC, abstractmethod
import math


# ----- 1. Abstract base class: declares WHAT, not HOW -----
class Shape(ABC):
    @abstractmethod
    def area(self):
        ...

    @abstractmethod
    def label(self):
        ...

    # concrete method built on top of the abstract ones
    def describe(self):
        return f"{self.label()} has area {self.area():.2f}"


# ----- 2. Concrete subclasses MUST implement every abstract method -----
class Circle(Shape):
    def __init__(self, r):
        self.r = r

    def area(self):
        return math.pi * self.r ** 2

    def label(self):
        return f"Circle with radius {self.r}"


class Square(Shape):
    def __init__(self, s):
        self.s = s

    def area(self):
        return self.s * self.s

    def label(self):
        return f"Square with side {self.s}"


# Shape()  # TypeError: Can't instantiate abstract class Shape with abstract methods
print(Circle(2).describe())  # Output: Circle with radius 2 has area 12.57
print(Square(3).describe())  # Output: Square with side 3 has area 9.00

# Cross-language note:
#   Python uses the `abc` module: ABC base + @abstractmethod. Instantiating a class
#   that still has unimplemented abstract methods raises TypeError. describe() is the
#   shared, concrete part of the contract.
