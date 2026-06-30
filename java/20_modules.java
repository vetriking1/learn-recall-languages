// ============================================================
// Topic:  Modules & Imports  (FOCUS: java.util, static import, java.lang implicit)
// Summary: import java.util.*, static Math.PI, package note, java.lang implicit.
// Run:     java java/20_modules.java   (Java 11+ single-file launch)
//
// NOTE: Single-file launch uses the default (unnamed) package — no package declaration.
//       Multi-file projects use: package com.example.app;
//
// KEY DIFFERENCES:
//   Python:  import module / from module import name
//   TS/JS:   import { x } from 'module' / require()
//   Rust:    mod + use crate::path
//   Java:    import / import static; java.lang auto-imported
//   C++:     #include <header>
// ============================================================

import java.util.List;
import java.util.Map;
import java.util.HashMap;

import static java.lang.Math.PI;
import static java.lang.Math.sqrt;

public class Modules {

    static String greet(String name) {
        // java.lang.String is implicit — no import needed
        return "Hi";
    }

    public static void main(String[] args) {
        // ----- 1. Static import — PI -----
        System.out.printf("pi: %.2f%n", PI);                      // Output: pi: 3.14

        // ----- 2. java.lang implicit — String -----
        System.out.println("greet: " + greet("World"));            // Output: greet: Hi

        // ----- 3. Static import — sqrt -----
        System.out.println("sqrt: " + sqrt(25.0));                // Output: sqrt: 5.0

        // ----- 4. java.util.* — Map alias -----
        Map<String, Integer> scores = new HashMap<>();
        scores.put("alice", 25);
        System.out.println("alias: " + scores.get("alice"));      // Output: alias: 25

        // ----- 5. java.util List (from import java.util.List) -----
        List<String> tags = List.of("main", "module");
        System.out.println(tags.get(0) + " " + tags.get(1));      // Output: main module
    }
}