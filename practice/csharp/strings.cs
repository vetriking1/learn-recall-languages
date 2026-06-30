// ============================================================
// Practice: Strings
// Summary: manual reverse, palindrome check, char counting.
// Run:     dotnet script practice/csharp/strings.cs
// ============================================================

using System;

// ----- 1. Reverse a string without a built-in reverse -----
string ReverseString(string s)
{
    string result = "";
    foreach (char ch in s) result = ch + result; // prepend each char
    return result;
}

// ----- 2. Palindrome check (ignore case and non-alphanumerics) -----
bool IsPalindrome(string s)
{
    var cleaned = new System.Text.StringBuilder();
    foreach (char c in s)
        if (char.IsLetterOrDigit(c)) cleaned.Append(char.ToLower(c));
    int i = 0, j = cleaned.Length - 1;
    while (i < j)
    {
        if (cleaned[i] != cleaned[j]) return false;
        i++;
        j--;
    }
    return true;
}

// ----- 3. Count vowels, consonants, special characters -----
(int, int, int) CountChars(string s)
{
    int vowels = 0, consonants = 0, special = 0;
    foreach (char c in s)
    {
        char lc = char.ToLower(c);
        if (lc >= 'a' && lc <= 'z')
        {
            if ("aeiou".IndexOf(lc) >= 0) vowels++;
            else consonants++;
        }
        else special++;
    }
    return (vowels, consonants, special);
}

Console.WriteLine(ReverseString("hello"));                      // Output: olleh
Console.WriteLine(IsPalindrome("A man a plan a canal Panama")); // Output: True
Console.WriteLine(IsPalindrome("hello"));                       // Output: False
var (v, c2, sp) = CountChars("Hello, World! 123");
Console.WriteLine($"({v}, {c2}, {sp})");                        // Output: (3, 7, 7)
