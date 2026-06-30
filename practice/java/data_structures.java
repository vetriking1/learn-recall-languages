// ============================================================
// Practice: Data Structures
// Summary: word frequency, two sum, dedupe, parens, merge, anagrams.
// Run:     java practice/java/data_structures.java   (Java 11+ single-file launch)
// ============================================================

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Deque;
import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.LinkedHashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

public class DataStructuresPractice {
    // ----- 1. Word frequency map -----
    static Map<String, Integer> wordFrequency(String text) {
        Map<String, Integer> freq = new LinkedHashMap<>();
        for (String word : text.toLowerCase().split("\\s+")) {
            freq.merge(word, 1, Integer::sum);
        }
        return freq;
    }

    // ----- 2. Two sum — return indices of pair that sums to target -----
    static int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> seen = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            int need = target - nums[i];
            if (seen.containsKey(need)) return new int[]{seen.get(need), i};
            seen.put(nums[i], i);
        }
        return new int[]{};
    }

    // ----- 3. Remove duplicates, preserve first-seen order -----
    static List<Integer> removeDuplicatesPreserveOrder(int[] arr) {
        Set<Integer> seen = new LinkedHashSet<>();
        List<Integer> result = new ArrayList<>();
        for (int x : arr) {
            if (seen.add(x)) result.add(x);
        }
        return result;
    }

    // ----- 4. Valid parentheses (stack) -----
    static boolean validParentheses(String s) {
        Deque<Character> stack = new ArrayDeque<>();
        Map<Character, Character> pairs = Map.of(')', '(', ']', '[', '}', '{');
        for (char c : s.toCharArray()) {
            if (pairs.containsValue(c)) stack.push(c);
            else if (pairs.containsKey(c)) {
                if (stack.isEmpty() || stack.pop() != pairs.get(c)) return false;
            }
        }
        return stack.isEmpty();
    }

    // ----- 5. Merge two sorted arrays -----
    static List<Integer> mergeTwoSorted(int[] a, int[] b) {
        List<Integer> merged = new ArrayList<>();
        int i = 0, j = 0;
        while (i < a.length && j < b.length) {
            if (a[i] <= b[j]) merged.add(a[i++]);
            else merged.add(b[j++]);
        }
        while (i < a.length) merged.add(a[i++]);
        while (j < b.length) merged.add(b[j++]);
        return merged;
    }

    // ----- 6. Group anagrams — sorted groups for stable output -----
    static List<List<String>> groupAnagrams(String[] words) {
        Map<String, List<String>> groups = new HashMap<>();
        for (String word : words) {
            char[] chars = word.toCharArray();
            Arrays.sort(chars);
            String key = new String(chars);
            groups.computeIfAbsent(key, k -> new ArrayList<>()).add(word);
        }
        List<List<String>> result = new ArrayList<>(groups.values());
        for (List<String> group : result) Collections.sort(group);
        result.sort((a, b) -> a.get(0).compareTo(b.get(0)));
        return result;
    }

    public static void main(String[] args) {
        System.out.println(wordFrequency("the cat sat on the mat cat")); // {the=2, cat=2, sat=1, on=1, mat=1}
        System.out.println(Arrays.toString(twoSum(new int[]{2, 7, 11, 15}, 9))); // [0, 1]
        System.out.println(removeDuplicatesPreserveOrder(new int[]{1, 2, 2, 3, 3, 4, 4})); // [1, 2, 3, 4]
        System.out.println(validParentheses("()[]{}"));  // true
        System.out.println(validParentheses("(]"));       // false
        System.out.println(mergeTwoSorted(new int[]{1, 3, 4, 6}, new int[]{2, 7})); // [1, 2, 3, 4, 6, 7]
        System.out.println(groupAnagrams(new String[]{"eat", "tea", "tan", "ate", "nat", "bat"})); // [[ate, eat, tea], [bat], [nat, tan]]
    }
}