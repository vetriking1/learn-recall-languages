# ============================================================
# Practice: Strings
# Summary: manual reverse, palindrome check, char counting.
# Run:     python practice/python/strings.py
# ============================================================

# ----- 1. Reverse a string without a built-in reverse -----
def reverse_string(s):
    result = ""
    for ch in s:
        result = ch + result   # prepend each char
    return result


# ----- 2. Palindrome check (ignore case and spaces) -----
def is_palindrome(s):
    cleaned = [c.lower() for c in s if c.isalnum()]
    i, j = 0, len(cleaned) - 1
    while i < j:
        if cleaned[i] != cleaned[j]:
            return False
        i += 1
        j -= 1
    return True


# ----- 3. Count vowels, consonants, special characters -----
def count_chars(s):
    vowels = consonants = special = 0
    for c in s:
        lc = c.lower()
        if lc.isalpha():
            if lc in "aeiou":
                vowels += 1
            else:
                consonants += 1
        else:
            special += 1
    return vowels, consonants, special


if __name__ == "__main__":
    print(reverse_string("hello"))                       # Output: olleh
    print(is_palindrome("A man a plan a canal Panama"))  # Output: True
    print(is_palindrome("hello"))                        # Output: False
    print(count_chars("Hello, World! 123"))              # Output: (3, 7, 7)
