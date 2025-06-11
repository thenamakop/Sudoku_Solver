# Sudoku Solver in C

This repository contains a **Sudoku Solver** implemented in C. The solver takes the input puzzle directly from the code in the `puzzle.c` file, processes it, and outputs the solution.

---

## 📚 About

- **Purpose:** Efficiently solve standard 9x9 Sudoku puzzles using a C implementation.
- **Input:** The puzzle is hardcoded in the `src/puzzle.c` file for easy modification and testing.
- **Output:** The solution is printed to the console upon execution.

---

## 🗂️ Structure

```
/
├── .github/
│   └── workflows/      # GitHub Actions workflows (CI/CD configurations)
├── include/            # Header files for the project
├── src/                # Source code, including puzzle.c and solver logic
├── Makefile            # Build instructions for compiling the solver
└── README.md           # Project documentation (this file)
```

---

## 🚀 Getting Started

1. **Clone the repository:**
   ```bash
   git clone https://github.com/thenamakop/Sudoku_Solver.git
   cd Sudoku_Solver
   ```

2. **Edit the Puzzle (Optional):**
   - Open `src/puzzle.c` and modify the puzzle array as desired.

3. **Build and run the solver using the Makefile:**
   ```bash
   make
   ./sudoku_solver
   ```

---

## 📝 Notes

- The primary puzzle input and changes should be made in `src/puzzle.c`.
- All core logic, including the solving algorithm, is implemented in the `src/` directory.
- Header files for function declarations and structures are in `include/`.
- The `Makefile` automates project compilation for convenience and reproducibility.

---

## 🤝 Contributing

Contributions, suggestions, and improvements are welcome!  
Feel free to fork the repository or open an issue.

---

## 📬 Contact

For questions or feedback, please reach out via [GitHub Issues](https://github.com/thenamakop/Sudoku_Solver/issues).

---

Happy Solving! 🧩
