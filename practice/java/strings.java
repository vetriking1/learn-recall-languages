// ============================================================
// Practice: Strings
// Summary: manual reverse, palindrome check, char counting.
// Run:     java practice/java/strings.java   (Java 11+ single-file launch)
// ============================================================

public class StringsPractice {
    // ----- 1. Reverse a string without a built-in reverse -----
    static String reverseString(String s) {
        String result = "";
        for (char ch : s.toCharArray()) result = ch + result; // prepend each char
        return result;
    }

    // ----- 2. Palindrome check (ignore case and non-alphanumerics) -----
    static boolean isPalindrome(String s) {
        StringBuilder cleaned = new StringBuilder();
        for (char c : s.toCharArray())
            if (Character.isLetterOrDigit(c)) cleaned.append(Character.toLowerCase(c));
        int i = 0, j = cleaned.length() - 1;
        while (i < j) {
            if (cleaned.charAt(i) != cleaned.charAt(j)) return false;
            i++;
            j--;
        }
        return true;
    }

    // ----- 3. Count vowels, consonants, special characters -----
    static int[] countChars(String s) {
        int vowels = 0, consonants = 0, special = 0;
        for (char c : s.toCharArray()) {
            char lc = Character.toLowerCase(c);
            if (lc >= 'a' && lc <= 'z') {
                if ("aeiou".indexOf(lc) >= 0) vowels++;
                else consonants++;
            } else {
                special++;
            }
        }
        return new int[]{vowels, consonants, special};
    }

    public static void main(String[] args) {
        System.out.println(reverseString("hello"));                      // olleh
        System.out.println(isPalindrome("A man a plan a canal Panama")); // true
        System.out.println(isPalindrome("hello"));                       // false
        int[] c = countChars("Hello, World! 123");
        System.out.println("(" + c[0] + ", " + c[1] + ", " + c[2] + ")"); // (3, 7, 7)
    }
}
