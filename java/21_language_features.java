// ============================================================
// Topic:  Language Features  (FOCUS: Streams, var, text blocks, switch, record, Optional)
// Summary: Modern Java syntax: Stream API, var, text blocks, switch expressions,
//          records (16+), Optional.
// Run:     java java/21_language_features.java   (Java 11+ single-file launch;
//          records require Java 16+)
//
// KEY DIFFERENCES:
//   Python:  list comprehensions / map+filter; no var; triple-quoted strings;
//            match/case (3.10+); dataclasses; Optional typing only
//   TS/JS:   .map/.filter on arrays; const/let inference; template literals;
//            switch; interfaces/types; null/undefined (no Optional type)
//   Rust:    iterators .map/.filter; let inference; raw strings r#"..."#;
//            match; struct + derive; Option<T>
//   Java:    Stream API; var (10+); text blocks (15+); switch -> (14+);
//            record (16+); java.util.Optional
//   C++:     ranges/views (C++20); auto; raw string literals; switch; struct;
//            std::optional
// ============================================================

import java.util.List;
import java.util.Optional;
import java.util.stream.Collectors;

public class LanguageFeatures {

    // ----- record (Java 16+) — compact immutable data carrier -----
    record Person(String name, int age) {}

    public static void main(String[] args) {
        // ----- 1. Streams map/filter -----
        String evens = List.of(1, 2, 3, 4, 5, 6).stream()
                .filter(n -> n % 2 == 0)
                .map(String::valueOf)
                .collect(Collectors.joining(" "));
        System.out.println("stream: " + evens);                  // Output: stream: 2 4 6

        // ----- 2. var local type inference (Java 10+) -----
        var greeting = "hello";
        System.out.println("var: " + greeting);                  // Output: var: hello

        // ----- 3. Text block (Java 15+) -----
        String block = """
                multi
                more
                """;
        String firstLine = block.lines().findFirst().orElse("").strip();
        System.out.println("block: " + firstLine);               // Output: block: multi

        // ----- 4. Switch expression with -> (Java 14+) -----
        int value = 5;
        String sign = switch (Integer.signum(value)) {
            case -1 -> "negative";
            case 0  -> "zero";
            default -> "positive";
        };
        System.out.println("switch: " + sign);                   // Output: switch: positive

        // ----- 5. record (Java 16+) -----
        Person bob = new Person("Bob", 30);
        System.out.println("record: " + bob.name() + " age=" + bob.age());
                                                                   // Output: record: Bob age=30

        // ----- 6. Optional — explicit absent/present wrapper -----
        Optional<Integer> maybe = Optional.of(7);
        System.out.println("optional: " + maybe.orElse(0));        // Output: optional: 7
    }
}