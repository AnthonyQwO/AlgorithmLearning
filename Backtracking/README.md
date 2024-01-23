# Backtracking

Backtracking is a general algorithmic technique used to systematically explore all possible solutions to a problem. It is particularly useful for solving problems that involve making a sequence of choices, where each choice leads to a set of subproblems. Backtracking follows a trial-and-error approach, attempting different choices at each decision point and backtracking when a chosen path does not lead to a valid solution.

## N-Queens Problem Solver

This C++ program solves the N-Queens problem using backtracking. The N-Queens problem is a classic puzzle where you need to place N chess queens on an N×N chessboard in such a way that no two queens threaten each other.

## Program Overview

### Constants
- `N`: The size of the chessboard, set to 8 in this program.

### Functions

#### `bool check(vector<string>& board, int x, int y, int n)`
This function checks whether it is safe to place a queen at position `(x, y)` on the chessboard.

- Parameters:
  - `board`: The current state of the chessboard.
  - `x`: Row index.
  - `y`: Column index.
  - `n`: Size of the chessboard.

- Returns:
  - `true` if it is safe to place a queen at the given position; otherwise, `false`.

#### `void Nqueen(vector<vector<string>>& res, vector<string>& board, int step, int n)`
This recursive function attempts to place queens on the chessboard using backtracking.

- Parameters:
  - `res`: Vector to store all solutions.
  - `board`: Current state of the chessboard.
  - `step`: Current row being processed.
  - `n`: Size of the chessboard.

- Operation:
  - If `step` is less than `n`, the function iterates through each column in the current row, attempting to place a queen.
  - If the placement is valid (checked using the `check` function), the queen is placed, and the function is called recursively for the next row.
  - Backtracking is used by undoing the queen placement after exploring all possibilities.

#### `vector<vector<string>> solveNQueens(int n)`
This function initializes the chessboard and starts the N-Queens problem-solving process.

- Parameters:
  - `n`: Size of the chessboard.

- Returns:
  - A vector containing all possible solutions to the N-Queens problem.

#### `void printallresult(vector<vector<string>> res)`
This function prints all solutions stored in the vector.

- Parameters:
  - `res`: Vector containing all solutions.

#### `int main()`
The `main` function initializes the chessboard, solves the N-Queens problem, and prints all solutions.

## Execution Flow

1. The program starts by initializing the chessboard (`board`) with all positions marked as empty (`'.'`).
2. The `solveNQueens` function is called with the size of the chessboard (`N`).
3. The `Nqueen` function is recursively called to find all solutions to the N-Queens problem.
4. Each solution is stored in the `res` vector.
5. Finally, the `printallresult` function is called to print all solutions.

## Example Output

The output consists of the chessboard configurations for each solution. Each queen is represented by the character 'Q', and empty squares are represented by '.'. Solutions are separated by blank lines.

Note: The program is configured to solve the 8-Queens problem (N=8) in this example.


## Sudoku Solver

This C++ program is designed to solve a 9x9 Sudoku puzzle using a recursive backtracking algorithm. The main logic is implemented in the `solveSudoku` function.

## Program Overview

### `printarr` Function
This function is responsible for printing the Sudoku board to the console. It takes a 2D vector representing the Sudoku board and prints each cell's value.

### `check` Function
The `check` function verifies if it's valid to place a character `cmp` at position `(x, y)` on the Sudoku board. It checks the row, column, and the 3x3 subgrid to ensure that the character does not violate Sudoku rules.

### `solveSudoku` Function
This is the heart of the Sudoku-solving logic. It uses a recursive backtracking approach to fill in the Sudoku board. The function iterates through each cell in the board. If the cell is empty (contains '.'), it tries placing numbers from '1' to '9' one by one. For each number, it checks if placing that number is valid using the `check` function. If valid, it sets the cell to that number and recursively calls itself. If the recursive call returns true, indicating a valid solution, it continues; otherwise, it backtracks by resetting the cell to '.' and tries the next number.

The function stops when it successfully fills all cells of the Sudoku board or exhausts all possibilities, returning either true (solution found) or false (no solution).

## Main Function
In the `main` function, a sample Sudoku board is initialized, displayed, and then passed to the `solveSudoku` function for solving. Finally, the solved Sudoku board is printed.

This program demonstrates a concise and efficient implementation of a Sudoku solver using recursive backtracking.