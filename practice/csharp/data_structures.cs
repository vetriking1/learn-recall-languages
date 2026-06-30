// ============================================================
// Practice: Data Structures
// Summary: word frequency, two sum, dedupe, parens, merge, anagrams.
// Run:     dotnet script practice/csharp/data_structures.cs
// ============================================================

using System;
using System.Collections.Generic;
using System.Linq;
// ----- 1. Word frequency in a sentence -----
Dictionary<string, int> WordFrequency(string sentence)
{
    var freq = new Dictionary<string, int>();
    foreach (var word in sentence.Split(' ', StringSplitOptions.RemoveEmptyEntries))
    {
        if (freq.ContainsKey(word)) freq[word]++;
        else freq[word] = 1;
    }
    return freq;
}

string FormatDict(Dictionary<string, int> d) =>
    "{" + string.Join(", ", d.Select(kv => $"'{kv.Key}': {kv.Value}")) + "}";

// ----- 2. Two sum — indices of two numbers that add to target -----
int[] TwoSum(int[] nums, int target)
{
    var seen = new Dictionary<int, int>();
    for (int i = 0; i < nums.Length; i++)
    {
        int need = target - nums[i];
        if (seen.TryGetValue(need, out int j)) return new[] { j, i };
        seen[nums[i]] = i;
    }
    return Array.Empty<int>();
}

// ----- 3. Remove duplicates, preserve first-seen order -----
List<int> RemoveDuplicatesPreserveOrder(int[] arr)
{
    var seen = new HashSet<int>();
    var result = new List<int>();
    foreach (var x in arr)
    {
        if (seen.Add(x)) result.Add(x);
    }
    return result;
}

// ----- 4. Valid parentheses (stack) -----
bool ValidParentheses(string s)
{
    var stack = new Stack<char>();
    foreach (char ch in s)
    {
        if (ch == '(' || ch == '[' || ch == '{') stack.Push(ch);
        else
        {
            if (stack.Count == 0) return false;
            char open = stack.Pop();
            if ((ch == ')' && open != '(') ||
                (ch == ']' && open != '[') ||
                (ch == '}' && open != '{')) return false;
        }
    }
    return stack.Count == 0;
}

// ----- 5. Merge two sorted arrays -----
List<int> MergeTwoSorted(int[] a, int[] b)
{
    var result = new List<int>();
    int i = 0, j = 0;
    while (i < a.Length && j < b.Length)
    {
        if (a[i] <= b[j]) result.Add(a[i++]);
        else result.Add(b[j++]);
    }
    while (i < a.Length) result.Add(a[i++]);
    while (j < b.Length) result.Add(b[j++]);
    return result;
}

// ----- 6. Group anagrams -----
List<List<string>> GroupAnagrams(string[] words)
{
    var groups = new Dictionary<string, List<string>>();
    foreach (var word in words)
    {
        var key = new string(word.OrderBy(c => c).ToArray());
        if (!groups.ContainsKey(key)) groups[key] = new List<string>();
        groups[key].Add(word);
    }
    return groups.Values
        .Select(g => g.OrderBy(w => w).ToList())
        .OrderBy(g => g[0])
        .ToList();
}

string FormatNestedLists(List<List<string>> groups) =>
    "[" + string.Join(", ", groups.Select(g => $"[{string.Join(", ", g.Select(w => $"'{w}'"))}]")) + "]";

Console.WriteLine(FormatDict(WordFrequency("the cat sat on the mat cat"))); // {'the': 2, 'cat': 2, 'sat': 1, 'on': 1, 'mat': 1}
Console.WriteLine($"[{string.Join(", ", TwoSum(new[] { 2, 7, 11, 15 }, 9))}]"); // [0, 1]
Console.WriteLine($"[{string.Join(", ", RemoveDuplicatesPreserveOrder(new[] { 1, 2, 2, 3, 1, 4, 3 }))}]"); // [1, 2, 3, 4]
Console.WriteLine(ValidParentheses("()[]{}"));  // True
Console.WriteLine(ValidParentheses("(]"));       // False
Console.WriteLine($"[{string.Join(", ", MergeTwoSorted(new[] { 1, 3, 4, 7 }, new[] { 2, 6 }))}]"); // [1, 2, 3, 4, 6, 7]
Console.WriteLine(FormatNestedLists(GroupAnagrams(new[] { "eat", "tea", "tan", "ate", "nat", "bat" }))); // [['ate', 'eat', 'tea'], ['bat'], ['nat', 'tan']]