# Rectangle Manipulation Program

## Project Description:

This project was created as a way to practice and reinforce my understanding of the **C programming language**. The goal was to develop a
simple yet functional **command-line program** that allows users to create, move, and merge rectangles in a grid-based matrix. By implementing 
this project, I was able to apply fundamental programming concepts such as **dynamic memory allocation, struct usage, file separation, and 
error handling**.

While this program is primarily an educational exercise, it also serves as a demonstration of **algorithmic problem-solving, matrix manipulation, 
and user command interpretation** in C.

---

## Features:

- **Create Rectangles:** Add rectangles with specified coordinates and dimensions.
- **Move Rectangles:** Shift existing rectangles left or right within the grid.
- **Apply Gravity:** Ensures that rectangles fall to the lowest available position in the matrix.
- **Merge Rectangles:** Combine two rectangles if they align in position and width.
- **Command Processing:** Accepts user commands via the terminal to interact with the program.
- **Error Handling:** Detects invalid commands, overlapping rectangles, and out-of-bounds movements.

---

## Growth Potential:

This project could be expanded with the following improvements:

- **Graphical Interface:** Implement a GUI using a graphics library to visualize rectangle movement.
- **Enhanced User Input Handling:** Support for file-based command execution instead of manual input.
- **Performance Optimization:** Improve efficiency in large-scale rectangle handling.
- **Additional Operations:** Introduce rotation, resizing, and color differentiation for rectangles.

---

## Requirements:

- **Compiler:** GCC (MinGW for Windows, or Clang/GCC for Linux/macOS)
- **Operating System:** Windows, Linux, or macOS

---

## How to Compile and Run:

### 1. Compilation

Use the following command in your terminal to compile the program:

```bash
gcc -o Rectangles.exe main.c analysis.c control.c visualization.c -Wall -Wextra -pedantic
```

For macOS/Linux:

```bash
gcc -o Rectangles main.c analysis.c control.c visualization.c -Wall -Wextra -pedantic
```

### 2. Running the Program

After compilation, run the program with:

```bash
./Rectangles.exe   # Windows
./Rectangles       # macOS/Linux
```

### 3. Running Tests

To execute the test cases, use:

```bash
gcc -o tests.exe tests.c analysis.c control.c visualization.c -Wall -Wextra -pedantic
./tests.exe        # Windows
./tests            # macOS/Linux
```

---

## Example Commands:

- **Create a Rectangle:**
  ```
  create 10,5+6,3
  ```
- **Move Right:**
  ```
  moveright 10,5+2
  ```
- **Move Left:**
  ```
  moveleft 10,5+3
  ```
- **Merge Rectangles:**
  ```
  merge 10,5+10,8
  ```

---

## Error Handling:

- **Invalid Command:** The input does not match any recognized command.
- **Out of Bounds:** The rectangle exceeds the matrix dimensions.
- **Overlap Detected:** A rectangle is placed over another existing rectangle.
- **Invalid Merge:** The rectangles cannot be merged due to misalignment.

---

## File Structure:

```
.
├── analysis.c           # Command parsing and validation
├── analysis.h           # Header file for analysis functions
├── control.c            # Core logic for rectangle manipulation
├── control.h            # Header file for control functions
├── visualization.c      # Functions for matrix visualization and error reporting
├── visualization.h      # Header file for visualization functions
├── main.c               # Main execution file
├── tests.c              # Unit tests for command functions
├── ReadMe.txt           # Documentation file
```

---

## Credits:

This project was developed as part of my learning process in C programming, focusing on **file organization, structured programming, and interactive 
command processing**.

**Developer:** [Toma Paraschiv]
