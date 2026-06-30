// ============================================================
// Topic:  File Handling  (FOCUS: java.nio.file.Files, Paths, Path)
// Summary: write, read, append, exists, line count, delete.
// Run:     java java/23_file_handling.java   (Java 11+ single-file launch)
//
// KEY DIFFERENCES:
//   Python:  open()/read()/write(); pathlib.Path
//   TS/JS:   fs.readFileSync / fs.promises; path.join
//   Rust:    std::fs::File; std::path::Path
//   Java:    java.nio.file.Files + Path (modern NIO.2 API)
//   C++:     std::fstream; std::filesystem::path
// ============================================================

import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.util.List;

public class FileHandling {

    public static void main(String[] args) throws IOException {
        // Demo file in the working directory (deleted at the end).
        Path path = Path.of("_alllangs_demo.txt");

        // ----- 1. Write text to a file -----
        Files.writeString(path, "hello file", StandardCharsets.UTF_8);
        System.out.println("write: ok");                                    // Output: write: ok

        // ----- 2. Read entire file as a String -----
        String content = Files.readString(path, StandardCharsets.UTF_8);
        System.out.println("read: " + content);                             // Output: read: hello file

        // ----- 3. Append to the file -----
        Files.writeString(
                path,
                "!",
                StandardCharsets.UTF_8,
                StandardOpenOption.APPEND
        );
        System.out.println("append: ok");                                 // Output: append: ok

        // ----- 4. Read again after append -----
        content = Files.readString(path, StandardCharsets.UTF_8);
        System.out.println("read: " + content);                             // Output: read: hello file!

        // ----- 5. Check whether the path exists -----
        boolean exists = Files.exists(path);
        System.out.println("exists: " + exists);                            // Output: exists: true

        // ----- 6. Count lines -----
        List<String> lines = Files.readAllLines(path, StandardCharsets.UTF_8);
        System.out.println("lines: " + lines.size());                       // Output: lines: 1

        // ----- 7. Delete the file -----
        Files.delete(path);
        System.out.println("deleted: ok");                                  // Output: deleted: ok

        // Cross-language note:
        //   Path.of("file.txt") == Python pathlib.Path("file.txt").
        //   Files.writeString / readString replace older FileWriter/BufferedReader.
        //   Paths.get(...) still works; Path.of is the Java 11+ shorthand.
        //   Always delete demo files so reruns start clean.
    }
}