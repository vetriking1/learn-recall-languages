// ============================================================
// Topic:  File Handling  (FOCUS: sync fs — write, read, append, exists, delete)
// Summary: node:fs sync APIs on a temp demo file; create, read, append, check, delete.
// Run:     npx ts-node typescript/23_file_handling.ts
//
// KEY DIFFERENCES:
//   Python:  open()/read()/write() + pathlib.Path.exists()
//   TS/Node: fs.writeFileSync / readFileSync / appendFileSync / existsSync / unlinkSync
//   Rust:    std::fs::write / read_to_string / OpenOptions::append
//   Java:    Files.write / Files.readString / Files.deleteIfExists
//   C++:     std::ofstream / std::ifstream / std::filesystem::exists
// ============================================================

"use strict";

import {
  writeFileSync,
  readFileSync,
  appendFileSync,
  existsSync,
  unlinkSync,
} from "node:fs";
import { join } from "node:path";

const filePath = join(__dirname, "..", "_alllangs_demo.txt");

writeFileSync(filePath, "hello file");
console.log("write: ok");

const firstRead = readFileSync(filePath, "utf8");
console.log(`read: ${firstRead}`);

appendFileSync(filePath, "!");
console.log("append: ok");

const secondRead = readFileSync(filePath, "utf8");
console.log(`read: ${secondRead}`);

console.log(`exists: ${existsSync(filePath)}`);

const lines = secondRead.split("\n").length;
console.log(`lines: ${lines}`);

unlinkSync(filePath);
console.log("deleted: ok");