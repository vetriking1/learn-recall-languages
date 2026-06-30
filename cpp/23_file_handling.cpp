// ============================================================
// Topic:  File Handling  (FOCUS: fstream, ofstream, ifstream, append, remove)
// Summary: Write, read, append, existence check, line count, delete — raw fstream.
// Run:     g++ -std=c++17 cpp/23_file_handling.cpp -o cpp/23_file_handling && cpp/23_file_handling
//
// KEY DIFFERENCES:
//   C++:     fstream / ofstream / ifstream, std::ios::app, std::remove (cstdio)
//   Python:  open(), read(), write(), os.remove()
//   Java:    Files, BufferedReader/Writer, Files.deleteIfExists()
//   C#:      File, StreamReader/Writer, File.Delete()
//   Rust:    std::fs::File, OpenOptions::append(), std::fs::remove_file()
//   TS/JS:   fs.readFileSync / writeFileSync / appendFileSync / unlinkSync
// ============================================================

#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>

int main() {
    const std::string path = "_alllangs_demo.txt";

    // ----- 1. Write with ofstream -----
    {
        std::ofstream out(path);
        out << "hello file";
        std::cout << "write: " << (out.good() ? "ok" : "fail") << std::endl;
    }

    // ----- 2. Read with ifstream -----
    {
        std::ifstream in(path);
        std::string content;
        std::getline(in, content);
        std::cout << "read: " << content << std::endl;
    }

    // ----- 3. Append with fstream in append mode -----
    {
        std::fstream file(path, std::ios::out | std::ios::app);
        file << "!";
        std::cout << "append: " << (file.good() ? "ok" : "fail") << std::endl;
    }

    // ----- 4. Read again with ifstream -----
    {
        std::ifstream in(path);
        std::string content;
        std::getline(in, content);
        std::cout << "read: " << content << std::endl;
    }

    // ----- 5. Existence check with ifstream -----
    {
        std::ifstream check(path);
        std::cout << "exists: " << (check.good() ? "true" : "false") << std::endl;
    }

    // ----- 6. Line count with ifstream -----
    {
        std::ifstream in(path);
        int lines = 0;
        std::string line;
        while (std::getline(in, line)) {
            ++lines;
        }
        std::cout << "lines: " << lines << std::endl;
    }

    // ----- 7. Delete with remove() -----
    {
        const int result = std::remove(path.c_str());
        std::cout << "deleted: " << (result == 0 ? "ok" : "fail") << std::endl;
    }

    return 0;
}