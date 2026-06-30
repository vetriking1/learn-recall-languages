// ============================================================
// Topic:  Modules & Imports  (FOCUS: ES module syntax, import/export, stdlib)
// Summary: export functions, import type, import * as alias, re-export pattern in comments.
// Run:     npx ts-node typescript/20_modules.ts
//
// NOTE: Single-file demo — exports live in this file; multi-file projects split helpers.
//       Circular imports (import top / export bottom of same file) are avoided here.
//
// Re-export patterns (multi-file):
//   export { greet, PI, sqrt } from './helpers';
//   export * from './utils';
//   export type { User } from './types';
//
// KEY DIFFERENCES:
//   Python:  import module / from module import name
//   TS/JS:   import { x } from 'module' / import * as alias / export
//   Rust:    mod + use crate::path
//   Java:    import / import static; java.lang auto-imported
//   C++:     #include <header>
// ============================================================

import { readFileSync } from "node:fs";
import * as alias from "node:fs";
import type { Stats } from "node:fs";
import * as path from "node:path";

// ----- Local exports (used by main below) -----
export const PI = 3.14;

export function greet(name: string): string {
  return "Hi";
}

export function sqrt(n: number): number {
  return Math.sqrt(n);
}

function main(): void {
  // ----- 1. Named export — PI -----
  console.log(`pi: ${PI.toFixed(2)}`); // Output: pi: 3.14

  // ----- 2. Local exported helper — greet -----
  console.log(`greet: ${greet("World")}`); // Output: greet: Hi

  // ----- 3. Exported util — sqrt -----
  console.log(`sqrt: ${sqrt(25.0).toFixed(1)}`); // Output: sqrt: 5.0

  // ----- 4. Namespace import * as alias — Map scores -----
  const scores = new Map<string, number>();
  scores.set("alice", 25);
  console.log(`alias: ${scores.get("alice")}`); // Output: alias: 25

  // ----- 5. Stdlib imports — readFileSync + alias namespace + import type -----
  const tsconfigPath = path.join(__dirname, "tsconfig.json");
  readFileSync(tsconfigPath, "utf8");
  const stats: Stats = alias.statSync(__filename);
  void stats;

  console.log("main module"); // Output: main module
}

main();

// Cross-language note:
//   import { readFileSync } from 'node:fs'  == Python from os import read
//   import * as alias from 'node:fs'        == Python import os as alias
//   import type { Stats }                   == type-only import (erased at compile)
//   export const / export function          == Python module-level public names