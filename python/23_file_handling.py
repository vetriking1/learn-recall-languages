# ============================================================
# Topic:  File Handling  (FOCUS: write, read, append, exists, lines, delete)
# Summary: pathlib + open() — create, read, append, inspect, remove a temp file.
# Run:     python python/23_file_handling.py
#
# KEY DIFFERENCES:
#   Python:  pathlib.Path | open() with modes "w"/"r"/"a"
#   TS/JS:   fs.writeFileSync / fs.readFileSync (node) | File API (browser)
#   Rust:    std::fs::File + std::io::Read/Write | std::path::Path
#   Java:    Files.write / Files.readString | java.io.File
#   C++:     std::fstream | std::filesystem::path
# ============================================================

from pathlib import Path

# Repo root (parent of python/) — portable regardless of cwd
DEMO_FILE = Path(__file__).resolve().parent.parent / "_alllangs_demo.txt"

# Remove leftover from a previous run
if DEMO_FILE.exists():
    DEMO_FILE.unlink()

# ----- 1. Write -----
DEMO_FILE.write_text("hello file", encoding="utf-8")
print("write: ok")  # Output: write: ok

# ----- 2. Read whole file -----
content = DEMO_FILE.read_text(encoding="utf-8").strip()
print(f"read: {content}")  # Output: read: hello file

# ----- 3. Append (same line) + read back -----
with DEMO_FILE.open("a", encoding="utf-8") as f:
    f.write("!")
print("append: ok")  # Output: append: ok
content = DEMO_FILE.read_text(encoding="utf-8").strip()
print(f"read: {content}")  # Output: read: hello file!

# ----- 4. Exists (+ optional size) -----
print(f"exists: {str(DEMO_FILE.exists()).lower()}")  # Output: exists: true

# ----- 5. Count lines -----
with DEMO_FILE.open(encoding="utf-8") as f:
    line_count = sum(1 for _ in f)
print(f"lines: {line_count}")  # Output: lines: 1

# ----- 6. Delete -----
DEMO_FILE.unlink()
assert not DEMO_FILE.exists()
print("deleted: ok")  # Output: deleted: ok

# Cross-language note:
#   Python open("w")     == C/Java "w" mode | Rust File::create | TS fs write
#   Python open("a")     == append mode everywhere — adds to end, no truncate
#   pathlib.Path.exists() == fs.existsSync (node) | Files.exists (Java) | path.exists (Rust)
#   Always specify encoding="utf-8" in Python 3 — unlike Java/Rust defaults, text mode
#   has no universal default across platforms (Windows may use cp1252 without it).