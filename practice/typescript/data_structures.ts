// ============================================================
// Practice: Data Structures
// Summary: word frequency, two sum, dedupe, parens, merge, anagrams.
// Run:     cd typescript && npx ts-node --project ../practice/typescript/tsconfig.json ../practice/typescript/data_structures.ts
// ============================================================

// ----- 1. Word frequency — count each word in a string -----
function wordFrequency(text: string): Record<string, number> {
  const freq = new Map<string, number>();
  for (const word of text.split(" ")) {
    freq.set(word, (freq.get(word) ?? 0) + 1);
  }
  return Object.fromEntries(freq);
}

// ----- 2. Two sum — indices of two numbers that add to target -----
function twoSum(nums: number[], target: number): number[] {
  const seen = new Map<number, number>();
  for (let i = 0; i < nums.length; i++) {
    const num = nums[i];
    const complement = target - num;
    if (seen.has(complement)) {
      return [seen.get(complement)!, i];
    }
    seen.set(num, i);
  }
  return [];
}

// ----- 3. Remove duplicates, preserve first-seen order -----
function removeDuplicatesPreserveOrder(arr: number[]): number[] {
  const seen = new Set<number>();
  const result: number[] = [];
  for (const x of arr) {
    if (!seen.has(x)) {
      seen.add(x);
      result.push(x);
    }
  }
  return result;
}

// ----- 4. Valid parentheses — stack-based bracket matching -----
function validParentheses(s: string): boolean {
  const stack: string[] = [];
  const pairs: Record<string, string> = { ")": "(", "]": "[", "}": "{" };
  for (const c of s) {
    if ("({[".includes(c)) {
      stack.push(c);
    } else if (")}]".includes(c)) {
      if (!stack.length || stack.pop() !== pairs[c]) return false;
    }
  }
  return stack.length === 0;
}

// ----- 5. Merge two sorted arrays — two-pointer merge -----
function mergeTwoSorted(a: number[], b: number[]): number[] {
  let i = 0;
  let j = 0;
  const result: number[] = [];
  while (i < a.length && j < b.length) {
    if (a[i] <= b[j]) {
      result.push(a[i++]);
    } else {
      result.push(b[j++]);
    }
  }
  return result.concat(a.slice(i), b.slice(j));
}

// ----- 6. Group anagrams — sort each group, sort groups by first word -----
function groupAnagrams(words: string[]): string[][] {
  const groups = new Map<string, string[]>();
  for (const word of words) {
    const key = [...word].sort().join("");
    if (!groups.has(key)) groups.set(key, []);
    groups.get(key)!.push(word);
  }
  const result = [...groups.values()].map((g) => [...g].sort());
  result.sort((a, b) => a[0].localeCompare(b[0]));
  return result;
}

console.log(wordFrequency("the cat sat on the mat cat")); // Output: { the: 2, cat: 2, sat: 1, on: 1, mat: 1 }
console.log(twoSum([2, 7, 11, 15], 9));                        // Output: [ 0, 1 ]
console.log(removeDuplicatesPreserveOrder([1, 2, 1, 3, 2, 4, 1])); // Output: [ 1, 2, 3, 4 ]
console.log(validParentheses("()[]{}"));                       // Output: true
console.log(validParentheses("([)]"));                         // Output: false
console.log(mergeTwoSorted([1, 4, 7], [2, 3, 6]));           // Output: [ 1, 2, 3, 4, 6, 7 ]
console.log(groupAnagrams(["eat", "tea", "tan", "ate", "nat", "bat"])); // Output: [ [ 'ate', 'eat', 'tea' ], [ 'bat' ], [ 'nat', 'tan' ] ]