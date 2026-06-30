// ============================================================
// Practice: Patterns
// Summary: right-angled triangle, centered pyramid.
// Run:     cd typescript && npx ts-node --project ../practice/typescript/tsconfig.json ../practice/typescript/patterns.ts
// ============================================================

// ----- 1. Right-angled triangle of stars -----
function rightTriangle(n: number): string[] {
  const lines: string[] = [];
  for (let i = 1; i <= n; i++) {
    lines.push("*".repeat(i));
  }
  return lines;
}

// ----- 2. Centered pyramid of stars (height h) -----
function pyramid(h: number): string[] {
  const lines: string[] = [];
  for (let i = 1; i <= h; i++) {
    const spaces = " ".repeat(h - i);
    const stars = "*".repeat(2 * i - 1);
    lines.push(spaces + stars);
  }
  return lines;
}

console.log("Right triangle (N=5):");
for (const line of rightTriangle(5)) console.log(line);
// *
// **
// ***
// ****
// *****

console.log("Pyramid (height=5):");
for (const line of pyramid(5)) console.log(line);
//     *
//    ***
//   *****
//  *******
// *********
