// ============================================================
// Practice: Algorithms
// Summary: linear search, binary search, Fibonacci (iter + rec).
// Run:     cd typescript && npx ts-node --project ../practice/typescript/tsconfig.json ../practice/typescript/algorithms.ts
// ============================================================

// ----- 1. Linear search -> index, or -1 if not found -----
function linearSearch(arr: number[], target: number): number {
  for (let i = 0; i < arr.length; i++) {
    if (arr[i] === target) return i;
  }
  return -1;
}

// ----- 2. Binary search on a SORTED array -> index, or -1 -----
function binarySearch(arr: number[], target: number): number {
  let lo = 0, hi = arr.length - 1;
  while (lo <= hi) {
    const mid = Math.floor((lo + hi) / 2);
    if (arr[mid] === target) return mid;
    else if (arr[mid] < target) lo = mid + 1;
    else hi = mid - 1;
  }
  return -1;
}

// ----- 3a. Fibonacci, iterative (N terms) -----
function fibIterative(n: number): number[] {
  const seq: number[] = [];
  let a = 0, b = 1;
  for (let i = 0; i < n; i++) {
    seq.push(a);
    [a, b] = [b, a + b];
  }
  return seq;
}

// ----- 3b. Fibonacci, recursive (nth term) -----
function fibRecursive(n: number): number {
  if (n < 2) return n;
  return fibRecursive(n - 1) + fibRecursive(n - 2);
}

console.log(linearSearch([4, 2, 7, 1, 9, 3], 7));   // Output: 2
console.log(linearSearch([4, 2, 7, 1, 9, 3], 5));   // Output: -1
console.log(binarySearch([1, 3, 5, 7, 9, 11], 7));  // Output: 3
console.log(binarySearch([1, 3, 5, 7, 9, 11], 4));  // Output: -1
console.log(fibIterative(10));                       // Output: [0,1,1,2,3,5,8,13,21,34]
console.log(Array.from({ length: 10 }, (_, i) => fibRecursive(i))); // same
