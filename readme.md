# 🐍 Classic Snake Game (C++)

A desktop implementation of the cult classic game "Snake," built with C++ and the SFML library. The game features classic gameplay with a difficulty level system and an intuitive menu.

# Preview

![Running game](https://private-user-images.githubusercontent.com/160499256/591925824-53d347b5-2c8c-4430-b863-b985a7b6891d.png?jwt=eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3Nzg2ODg5NzAsIm5iZiI6MTc3ODY4ODY3MCwicGF0aCI6Ii8xNjA0OTkyNTYvNTkxOTI1ODI0LTUzZDM0N2I1LTJjOGMtNDQzMC1iODYzLWI5ODVhN2I2ODkxZC5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjYwNTEzJTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI2MDUxM1QxNjExMTBaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT0wYmFhODViOTNmNzVhMzljYzBkYWExZWE3MTdhMTAzZjViODUyNTRlYzM1YjhkZDRkNjNmOTcwYjU1ODU3ZWUzJlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCZyZXNwb25zZS1jb250ZW50LXR5cGU9aW1hZ2UlMkZwbmcifQ.i7RrJzfWDQBdTRQokvDvettCM2XCmvT8tYRk_Z1dva0)

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