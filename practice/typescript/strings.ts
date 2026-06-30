// ============================================================
// Practice: Strings
// Summary: manual reverse, palindrome check, char counting.
// Run:     cd typescript && npx ts-node --project ../practice/typescript/tsconfig.json ../practice/typescript/strings.ts
// ============================================================

// ----- 1. Reverse a string without a built-in reverse -----
function reverseString(s: string): string {
  let result = "";
  for (const ch of s) {
    result = ch + result; // prepend each char
  }
  return result;
}

// ----- 2. Palindrome check (ignore case and non-alphanumerics) -----
function isPalindrome(s: string): boolean {
  const cleaned = [...s.toLowerCase()].filter((c) => /[a-z0-9]/.test(c));
  let i = 0, j = cleaned.length - 1;
  while (i < j) {
    if (cleaned[i] !== cleaned[j]) return false;
    i++;
    j--;
  }
  return true;
}

// ----- 3. Count vowels, consonants, special characters -----
function countChars(s: string): [number, number, number] {
  let vowels = 0, consonants = 0, special = 0;
  for (const c of s) {
    const lc = c.toLowerCase();
    if (/[a-z]/.test(lc)) {
      if ("aeiou".includes(lc)) vowels++;
      else consonants++;
    } else {
      special++;
    }
  }
  return [vowels, consonants, special];
}

console.log(reverseString("hello"));                      // Output: olleh
console.log(isPalindrome("A man a plan a canal Panama")); // Output: true
console.log(isPalindrome("hello"));                       // Output: false
console.log(countChars("Hello, World! 123"));             // Output: [ 3, 7, 7 ]
