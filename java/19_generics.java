// ============================================================
// Topic:  Generics  (FOCUS: generic methods, classes, bounded types, wildcards)
// Summary: Generic methods, generic class, bounded type param, wildcards note.
// Run:     java java/19_generics.java   (Java 11+ single-file launch)
//
// KEY DIFFERENCES:
//   Python:  typing.TypeVar / Generic (runtime erasure — no true generics)
//   TS/JS:   generics compile-time only; erased at runtime
//   Rust:    monomorphized generics (zero-cost, no erasure)
//   Java:    type erasure; bounded wildcards <? extends T>, <? super T>
//   C++:     templates (compile-time instantiation)
// ============================================================

import java.util.ArrayList;
import java.util.List;

public class Generics {

    // ----- Generic class -----
    static class Box<T> {
        private final T value;

        Box(T value) {
            this.value = value;
        }

        T get() {
            return value;
        }
    }

    // ----- Generic pair class -----
    static class Pair<K, V> {
        private final K key;
        private final V value;

        Pair(K key, V value) {
            this.key = key;
            this.value = value;
        }

        @Override
        public String toString() {
            return key + " " + value;
        }
    }

    // ----- Generic method — swap two elements -----
    static <T> void swap(T[] arr, int i, int j) {
        T temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    // ----- Bounded type parameter <T extends Comparable<T>> -----
    static <T extends Comparable<T>> T max(T a, T b) {
        return a.compareTo(b) >= 0 ? a : b;
    }

    // ----- Wildcards note: <? extends Number> for read-only upper bound -----
    static int sumNumbers(List<? extends Number> numbers) {
        int total = 0;
        for (Number n : numbers) {
            total += n.intValue();
        }
        return total;
    }

    public static void main(String[] args) {
        // ----- 1. Generic method — swap -----
        Integer[] nums = {1, 2};
        swap(nums, 0, 1);
        System.out.println("swap: " + nums[0] + " " + nums[1]); // Output: swap: 2 1

        // ----- 2. Generic class — Box<String> -----
        Box<String> box = new Box<>("hello");
        System.out.println("box: " + box.get());                  // Output: box: hello

        // ----- 3. Bounded type param — max -----
        System.out.println("max: " + max(9, 3));                  // Output: max: 9

        // ----- 4. Generic pair -----
        Pair<Integer, String> pair = new Pair<>(1, "two");
        System.out.println("pair: " + pair);                      // Output: pair: 1 two

        // ----- 5. Wildcards — List<? extends Number> (count items) -----
        List<Integer> items = new ArrayList<>();
        items.add(10);
        items.add(5);
        items.add(10);
        System.out.println("items: " + items.size());             // Output: items: 3
    }
}