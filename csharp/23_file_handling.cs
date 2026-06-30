// ============================================================
// Topic:  File Handling
// Summary: Write, read, append, exists check, line count, delete via System.IO.File.
// Run:     dotnet script csharp/23_file_handling.cs
//
// KEY DIFFERENCES:
//   C#:     System.IO.File / FileStream; Path.Combine for cross-platform paths
//   Python: open(), pathlib.Path; with-statement for auto-close
//   TS/JS:  fs.readFileSync / fs.promises; path.join
//   Rust:   std::fs; std::path::PathBuf
//   Java:   java.nio.file.Files, Paths.get
//   C++:    std::fstream; std::filesystem::path
// ============================================================

using System;
using System.IO;

// ----- 1. Temp path — cross-platform via Path.GetTempPath() -----
string path = Path.Combine(Path.GetTempPath(), "_alllangs_demo.txt");

// ----- 2. Write text to file -----
File.WriteAllText(path, "hello file");
Console.WriteLine("write: ok");                        // write: ok

// ----- 3. Read entire file -----
string content = File.ReadAllText(path);
Console.WriteLine($"read: {content}");                 // read: hello file

// ----- 4. Append to file -----
File.AppendAllText(path, "!");
Console.WriteLine("append: ok");                       // append: ok

// ----- 5. Read after append -----
content = File.ReadAllText(path);
Console.WriteLine($"read: {content}");                 // read: hello file!

// ----- 6. Check existence -----
Console.WriteLine($"exists: {File.Exists(path).ToString().ToLowerInvariant()}"); // exists: true

// ----- 7. Count lines -----
int lines = File.ReadAllLines(path).Length;
Console.WriteLine($"lines: {lines}");                    // lines: 1

// ----- 8. Delete file -----
File.Delete(path);
Console.WriteLine("deleted: ok");                      // deleted: ok