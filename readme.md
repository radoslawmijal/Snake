# 🐍 Classic Snake Game (C++)

A desktop implementation of the cult classic game "Snake," built with C++ and the SFML library. The game features classic gameplay with a difficulty level system and an intuitive menu.

## 📋 Prerequisites

Before building the project, ensure you have the following installed on your system:

* **C++ Compiler:** A compiler supporting C++17 (e.g., GCC, Clang, or MSVC).
* **CMake:** Version 3.26 or higher.
* **SFML Library:** Version 2.5 or higher (Graphics and Audio modules).
    * **Ubuntu/Debian:** `sudo apt-get install libsfml-dev`
    * **macOS:** `brew install sfml`
    * **Windows:** Recommendation is to use a package manager like `vcpkg` or download the SDK from the [SFML website](https://www.sfml-dev.org/).

## 🎮 Game Features
* **3 Difficulty Levels:** Choose a game pace suited to your reflexes (Easy, Medium, Hard).
* **Dynamic Growth:** Each apple eaten increases the snake's length and your score.
* **Collision Mechanics:** The game ends upon hitting a wall or your own tail.
* **Interactive Menu:** Fully keyboard-operated navigation using Tab and Enter.

## ⌨️ Controls

| Key | Action |
| :--- | :--- |
| **W / A / S / D** | Move the snake (Up, Left, Down, Right) |
| **TAB** | Toggle through menu options |
| **ENTER** | Confirm selection |
| **ESC** | Return to Main Menu / Exit |

## 🏆 Scoring System & Rankings
The game features a built-in local save system, allowing you to track your progress and compete against your own high scores stored in a local file.

## 📁 File Structure
| File/Folder | Description |
| :--- | :--- |
| `Images/` | Directory containing textures for the snake, apples, and background. |
| `Snake` | The main executable file (generated after build). |

## 🚀 How to Run

1. **Clone the repository:**
   ```bash
   git clone [https://github.com/radoslawmijal/Snake](https://github.com/radoslawmijal/Snake)
   cd Snake 

2.  **Build project**
    ```bash
    cmake -S . -B build

3. **Go to 'build' folder**
    ```bash
    cd build
    make

4. **Run the file and have fun**
    ```bash
    ./Snake