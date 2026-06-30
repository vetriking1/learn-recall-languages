// ============================================================
// Topic:  File Handling
// Summary: fs::write, read_to_string, OpenOptions append, metadata, remove_file.
// Run:     rustc --edition 2021 rust/23_file_handling.rs -o rust/23_file_handling.exe && rust/23_file_handling.exe
//
// KEY DIFFERENCES:
//   Python:  open(), read(), write(), pathlib.Path
//   TS/JS:   fs.readFileSync, fs.writeFileSync, fs.appendFileSync
//   Rust:    std::fs + std::io; Result for I/O errors; Path/PathBuf
//   Java:    Files.readString, Files.write, BufferedWriter
//   C++:     fstream, std::filesystem
// ============================================================

use std::fs::{self, OpenOptions};
use std::io::Write;
use std::path::PathBuf;

fn main() {
    let path: PathBuf = std::env::temp_dir().join("_alllangs_demo.txt");

    // Remove leftover from a previous run (ignore if missing)
    let _ = fs::remove_file(&path);

    // ----- 1. Write entire file (creates or overwrites) -----
    fs::write(&path, "hello file").expect("write failed");
    println!("write: ok");

    // ----- 2. Read whole file as String -----
    let content = fs::read_to_string(&path).expect("read failed");
    println!("read: {}", content.trim());

    // ----- 3. Append with OpenOptions -----
    let mut file = OpenOptions::new()
        .append(true)
        .open(&path)
        .expect("open for append failed");
    file.write_all(b"!").expect("append failed");
    println!("append: ok");

    // ----- 4. Read again after append -----
    let content = fs::read_to_string(&path).expect("read failed");
    println!("read: {}", content.trim());

    // ----- 5. metadata — check file exists -----
    let exists = fs::metadata(&path).is_ok();
    println!("exists: {}", exists);

    // ----- 6. Line count from content -----
    let lines = content.lines().count();
    println!("lines: {}", lines);

    // ----- 7. Delete file -----
    fs::remove_file(&path).expect("remove failed");
    println!("deleted: ok");
}