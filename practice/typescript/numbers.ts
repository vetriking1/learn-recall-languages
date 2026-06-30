// ============================================================
// Practice: Numbers
// Summary: prime check, multiplication table, Euclidean GCD.
// Run:     cd typescript && npx ts-node --project ../practice/typescript/tsconfig.json ../practice/typescript/numbers.ts
// ============================================================

// ----- 1. Is a number prime? -----
function isPrime(n: number): boolean {
  if (n < 2) return false;
  for (let i = 2; i * i <= n; i++) {
    if (n % i === 0) return false;
  }
  return true;
}

// ----- 2. Multiplication table for n, 1..limit -----
function multiplicationTable(n: number, limit: number): string[] {
  const rows: string[] = [];
  for (let i = 1; i <= limit; i++) {
    rows.push(`${n} x ${i} = ${n * i}`);
  }
  return rows;
}

// ----- 3. GCD via the Euclidean algorithm -----
function gcd(a: number, b: number): number {
  while (b !== 0) {
    [a, b] = [b, a % b];
  }
  return a;
}

console.log(isPrime(7), isPrime(10));          // Output: true false
for (const line of multiplicationTable(7, 10)) {
  console.log(line);                            // 7 x 1 = 7 ... 7 x 10 = 70
}
console.log(gcd(48, 18));                       // Output: 6
