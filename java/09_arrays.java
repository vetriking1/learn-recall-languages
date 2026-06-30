// ============================================================
// Topic:  Arrays / Lists  (FOCUS: methods & operations)
// Summary: ArrayList create, add, remove, slice, search, sort, sum.
// Run:     java java/09_arrays.java   (Java 11+ single-file launch)
//
// KEY DIFFERENCE the user cares about:
//   Java List: l.add(x), l.remove(i)   |   Python: l.append(x), l.pop(i)
//   ⚠ remove(int) removes by INDEX; remove(Integer) removes by VALUE.
//   Fixed array int[] vs growable List/ArrayList.
// ============================================================

import java.util.ArrayList;
import java.util.List;
import java.util.Arrays;
import java.util.Collections;

public class ArraysLists {
    public static void main(String[] args) {
        // ----- 1. Create & access (ArrayList = growable list) -----
        List<Integer> l = new ArrayList<>(Arrays.asList(10, 20, 30));
        System.out.println(l.get(0));             // 10  (Python: l[0]; no [] on a List)
        System.out.println(l.get(l.size() - 1));  // 30  (Python: l[-1])
        System.out.println(l.size());             // 3   (Python: len(l); TS: l.length)

        // ----- 2. Add to END -----
        l.add(40);                                // (Python: append; TS: push)
        System.out.println(l);                    // [10, 20, 30, 40]
        l.addAll(Arrays.asList(50, 60));          // add many
        System.out.println(l);                    // [10, 20, 30, 40, 50, 60]

        // ----- 3. Add to FRONT (insert at index 0) -----
        l.add(0, 5);                              // (Python: l.insert(0,5); TS: unshift)
        System.out.println(l);                    // [5, 10, 20, 30, 40, 50, 60]

        // ----- 4. Remove from END -----
        l.remove(l.size() - 1);                   // remove last INDEX
        System.out.println(l);                    // [5, 10, 20, 30, 40, 50]

        // ----- 5. Remove from FRONT -----
        l.remove(0);                              // remove index 0 (TS: shift; Python: pop(0))
        System.out.println(l);                    // [10, 20, 30, 40, 50]

        // ----- 6. Remove by VALUE (wrap with Integer.valueOf!) -----
        l.remove(Integer.valueOf(30));            // ⚠ remove(30) would remove INDEX 30
        System.out.println(l);                    // [10, 20, 40, 50]

        // ----- 7. Slice (subList view) -----
        System.out.println(l.subList(1, 3));      // [20, 40]  (Python: l[1:3])

        // ----- 8. Search / membership -----
        System.out.println(l.contains(20));       // true  (Python: 20 in l)
        System.out.println(l.indexOf(40));        // 2     (Python: l.index(40))

        // ----- 9. Reverse / sort -----
        List<Integer> copy = new ArrayList<>(l);
        Collections.reverse(copy);
        System.out.println(copy);                 // [50, 40, 20, 10]
        Collections.sort(l);
        System.out.println(l);                    // [10, 20, 40, 50]
        l.sort(Collections.reverseOrder());
        System.out.println(l);                    // [50, 40, 20, 10]

        // ----- 10. Sum (stream) -----
        int sum = l.stream().mapToInt(Integer::intValue).sum();
        System.out.println(sum);                  // 120

        // Cross-language note:
        //   Use List/ArrayList for a growable list; arrays (int[]) are fixed-size.
        //   Access with .get(i) / .set(i, v) — no [] indexing on a List.
        //   ⚠ remove(int) removes by INDEX; remove(Integer) removes by VALUE.
        //   No negative indexing; no slice operator (use subList).
    }
}
