# ============================================================
# Topic:  Classes & Objects
# Summary: Define a class (state + behavior), construct instances, call methods.
# Run:     python python/10_classes.py
# ============================================================

# ----- 1. Define a class with a constructor and methods -----
class Person:
    # __init__ is the constructor; self is the instance (like `this`)
    def __init__(self, name, age):
        self.name = name   # instance fields/attributes
        self.age = age

    # ----- 2. Instance method (uses self) -----
    def greet(self):
        return f"Hi, I'm {self.name} and I'm {self.age}"

    # ----- 3. Method that mutates instance state -----
    def birthday(self):
        self.age += 1


# ----- 4. Create objects (instances) and call methods -----
p1 = Person("Vetri", 22)
p2 = Person("Asha", 30)
print(p1.greet())   # Output: Hi, I'm Vetri and I'm 22
print(p2.greet())   # Output: Hi, I'm Asha and I'm 30

p1.birthday()       # mutate p1's state
print(p1.greet())   # Output: Hi, I'm Vetri and I'm 23

# Cross-language note:
#   Python: constructor is __init__; the instance is the explicit `self` param.
#   No `new` keyword. Attributes are created by assigning to self.x.
#   Fields are public by convention (use _name / __name for "private"); see 11_encapsulation.
