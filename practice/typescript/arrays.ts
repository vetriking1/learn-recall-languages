// ============================================================
// Practice: Arrays
// Summary: max/min, sum/average, in-place reverse, remove dups.
// Run:     cd typescript && npx ts-node --project ../practice/typescript/tsconfig.json ../practice/typescript/arrays.ts
// ============================================================

// ----- 1. Max and min of an array -----
function maxMin(arr: number[]): [number, number] {
  let mx = arr[0], mn = arr[0];
  for (const x of arr) {
    if (x > mx) mx = x;
    if (x < mn) mn = x;
  }
  return [mx, mn];
}

// ----- 2. Sum and average -----
function sumAvg(arr: number[]): [number, number] {
  let total = 0;
  for (const x of arr) total += x;
  return [total, total / arr.length];
}

// ----- 3. Reverse in place (two-pointer swap, no extra array) -----
function reverseInPlace(arr: number[]): number[] {
  let i = 0, j = arr.length - 1;
  while (i < j) {
    [arr[i], arr[j]] = [arr[j], arr[i]];
    i++;
    j--;
  }
  return arr;
}

// ----- 4. Remove duplicates from a SORTED array (in place) -----
function removeDuplicates(arr: number[]): number[] {
  if (arr.length === 0) return arr;
  let write = 1;
  for (let read = 1; read < arr.length; read++) {
    if (arr[read] !== arr[write - 1]) {
      arr[write] = arr[read];
      write++;
    }
  }
  return arr.slice(0, write);
}

console.log(maxMin([3, 7, 1, 9, 2]));            // Output: [ 9, 1 ]
console.log(sumAvg([10, 20, 30, 40]));           // Output: [ 100, 25 ]
console.log(reverseInPlace([1, 2, 3, 4, 5]));    // Output: [ 5, 4, 3, 2, 1 ]
console.log(removeDuplicates([1, 1, 2, 2, 3, 4, 4, 5])); // Output: [ 1, 2, 3, 4, 5 ]
