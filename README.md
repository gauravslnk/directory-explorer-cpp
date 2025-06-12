# 📁 Directory Explorer – C++ (Cross-Platform)

A simple and beginner-friendly C++ program that lists all files and folders in the current directory. It detects whether each entry is a file or a folder and prints it in a clean, formatted way.

✨ Works perfectly on **Windows**, **Linux**, and **macOS**.

---

## 🛠️ Built With

- C++
- `dirent.h` for reading directories
- `sys/stat.h` for file/folder metadata
- `iomanip` for clean output formatting
- Platform-specific headers: `windows.h` (Windows), `unistd.h` (Linux/macOS)

---

## 🚀 Getting Started

### 1. Clone the Repository

```bash
git clone https://github.com/your-username/directory-explorer-cpp.git
cd directory-explorer-cpp
````

### 2. Compile the Code

#### On Windows (with MinGW):

```bash
g++ main.cpp -o explorer.exe
```

#### On Linux/macOS:

```bash
g++ main.cpp -o explorer
```

### 3. Run the Program

```bash
./explorer       # macOS/Linux
explorer.exe     # Windows
```

---

## 💡 Sample Output

```
main.cpp                      --> is a FILE.
readme.md                     --> is a FILE.
```
---

## 📌 To Do (Optional Improvements)

* [ ] Add file size display
* [ ] Show last modified time
* [ ] Recursively list subdirectories
* [ ] Add GUI version with C++ Qt or ImGui

---

## 📄 License

This project is open-source and free to use under the [MIT License](LICENSE).

---


