# ============================================================
# Topic:  Inheritance
# Summary: A subclass reuses a base class, overrides methods, calls super().
# Run:     python python/12_inheritance.py
# ============================================================

class Animal:
    def __init__(self, name):
        self.name = name

    def sound(self):
        return "some sound"

    def describe(self):
        return f"{self.name} says {self.sound()}"


# ----- 1. Subclass with extra state; super() calls the base constructor -----
class Dog(Animal):
    def __init__(self, name, breed):
        super().__init__(name)      # run Animal.__init__
        self.breed = breed

    def sound(self):                # override
        return "Woof"

    def describe(self):             # extend the base behavior
        return f"{super().describe()} ({self.breed})"


# ----- 2. Subclass that only overrides one method -----
class Cat(Animal):
    def sound(self):
        return "Meow"


print(Animal("Creature").describe())     # Output: Creature says some sound
print(Dog("Rex", "Labrador").describe()) # Output: Rex says Woof (Labrador)
print(Cat("Whiskers").describe())        # Output: Whiskers says Meow

# Cross-language note:
#   Python: class Dog(Animal) inherits; super() reaches the base ctor/method.
#   describe() (defined once on Animal) calls self.sound(), which dispatches to the
#   subclass override — that's runtime polymorphism (see 13_polymorphism).
