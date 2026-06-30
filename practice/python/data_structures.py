# ============================================================
# Practice: Data Structures
# Summary: word frequency, two sum, dedupe, parens, merge, anagrams.
# Run:     python practice/python/data_structures.py
# ============================================================

# ----- 1. Word frequency — count each word in a string -----
def word_frequency(text):
    freq = {}
    for word in text.split():
        freq[word] = freq.get(word, 0) + 1
    return freq


# ----- 2. Two sum — indices of two numbers that add to target -----
def two_sum(nums, target):
    seen = {}
    for i, num in enumerate(nums):
        complement = target - num
        if complement in seen:
            return [seen[complement], i]
        seen[num] = i
    return []


# ----- 3. Remove duplicates, preserve first-seen order -----
def remove_duplicates_preserve_order(arr):
    seen = set()
    result = []
    for x in arr:
        if x not in seen:
            seen.add(x)
            result.append(x)
    return result


# ----- 4. Valid parentheses — stack-based bracket matching -----
def valid_parentheses(s):
    stack = []
    pairs = {")": "(", "]": "[", "}": "{"}
    for c in s:
        if c in "([{":
            stack.append(c)
        elif c in ")]}":
            if not stack or stack.pop() != pairs[c]:
                return False
    return len(stack) == 0


# ----- 5. Merge two sorted arrays — two-pointer merge -----
def merge_two_sorted(a, b):
    i, j = 0, 0
    result = []
    while i < len(a) and j < len(b):
        if a[i] <= b[j]:
            result.append(a[i])
            i += 1
        else:
            result.append(b[j])
            j += 1
    result.extend(a[i:])
    result.extend(b[j:])
    return result


# ----- 6. Group anagrams — sort each group, sort groups by first word -----
def group_anagrams(words):
    groups = {}
    for word in words:
        key = tuple(sorted(word))
        groups.setdefault(key, []).append(word)
    result = [sorted(g) for g in groups.values()]
    result.sort(key=lambda g: g[0])
    return result


if __name__ == "__main__":
    print(word_frequency("the cat sat on the mat cat"))      # Output: {'the': 2, 'cat': 2, 'sat': 1, 'on': 1, 'mat': 1}
    print(two_sum([2, 7, 11, 15], 9))                        # Output: [0, 1]
    print(remove_duplicates_preserve_order([1, 2, 1, 3, 2, 4, 1]))  # Output: [1, 2, 3, 4]
    print(valid_parentheses("()[]{}"))                       # Output: True
    print(valid_parentheses("([)]"))                         # Output: False
    print(merge_two_sorted([1, 4, 7], [2, 3, 6]))           # Output: [1, 2, 3, 4, 6, 7]
    print(group_anagrams(["eat", "tea", "tan", "ate", "nat", "bat"]))  # Output: [['ate', 'eat', 'tea'], ['bat'], ['nat', 'tan']]