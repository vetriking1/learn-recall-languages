# ============================================================
# Topic:  Polymorphism
# Summary: Treat different types through one interface; the right method runs.
# Run:     python python/13_polymorphism.py
# ============================================================

import math


class Shape:
    def name(self):
        return "Shape"

    def area(self):
        return 0.0


class Circle(Shape):
    def __init__(self, r):
        self.r = r

    def name(self):
        return "Circle"

    def area(self):
        return math.pi * self.r ** 2


class Rectangle(Shape):
    def __init__(self, w, h):
        self.w = w
        self.h = h

    def name(self):
        return "Rectangle"

    def area(self):
        return self.w * self.h


# ----- One loop over mixed types; each call dispatches to the real class -----
shapes = [Circle(2), Rectangle(3, 4)]
total = 0.0
for s in shapes:
    print(f"{s.name()} area: {s.area():.2f}")
    total += s.area()
print(f"Total area: {total:.2f}")
# Output:
# Circle area: 12.57
# Rectangle area: 12.00
# Total area: 24.57

# Cross-language note:
#   Python is duck-typed: any object with name()/area() works in the loop — no shared
#   base class is even required. The call s.area() resolves to the object's real type.
