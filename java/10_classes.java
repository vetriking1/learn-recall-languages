// ============================================================
// Topic:  Classes & Objects
// Summary: Define a class (state + behavior), construct instances, call methods.
// Run:     java java/10_classes.java   (Java 11+ single-file launch)
// ============================================================

public class Classes {
    public static void main(String[] args) {
        // ----- 4. Create objects with `new` and call methods -----
        Person p1 = new Person("Vetri", 22);
        Person p2 = new Person("Asha", 30);
        System.out.println(p1.greet()); // Output: Hi, I'm Vetri and I'm 22
        System.out.println(p2.greet()); // Output: Hi, I'm Asha and I'm 30

        p1.birthday();                   // mutate p1's state
        System.out.println(p1.greet()); // Output: Hi, I'm Vetri and I'm 23
    }
}

// ----- 1. Define a class with a constructor and methods -----
class Person {
    private String name; // fields (private backing state)
    private int age;

    // ----- constructor: same name as the class, no return type -----
    Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    // ----- 2. Instance method -----
    String greet() {
        return "Hi, I'm " + name + " and I'm " + age;
    }

    // ----- 3. Method that mutates instance state -----
    void birthday() {
        age += 1;
    }
}

// Cross-language note:
//   Java: constructor shares the class name and has no return type; instance is `this`.
//   Every class normally lives in its own file; here a single file holds two
//   top-level classes (only one may be `public`) for a runnable single-file demo.
//   Fields default to package-private; mark `private` and expose getters (see 11_encapsulation).
