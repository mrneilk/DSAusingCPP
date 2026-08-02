#include <iostream>
#include <vector>

using namespace std;

// Define the size of the Sudoku grid - Globally defined as 9 for a standard Sudoku puzzle
#define N 9

// Function to print the Sudoku grid nicely
void printGrid(const vector<vector<int>>& grid) {
    for (int r = 0; r < N; r++) {
        if (r % 3 == 0 && r != 0) {
            cout << "---------------------\n";
        }
        for (int c = 0; c < N; c++) {
            if (c % 3 == 0 && c != 0) {
                cout << "| ";
            }
            if (grid[r][c] == 0) {
                cout << ". ";
            } else {
                cout << grid[r][c] << " ";
            }
        }
        cout << "\n";
    }
}

// Function to check if placing 'num' at grid[row][col] is valid
bool isValid(const vector<vector<int>>& grid, int row, int col, int num) {
    // Check row and column
    for (int i = 0; i < N; i++) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return false;
        }
    }

    // Check 3x3 subgrid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            if (grid[r + startRow][c + startCol] == num) {
                return false;
            }
        }
    }

    return true;
}

// Main backtracking function to solve the Sudoku
bool solveSudoku(vector<vector<int>>& grid) {
    int row = -1;
    int col = -1;
    bool isEmpty = false;

    // 1. Find an empty cell (0)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 0) {
                row = i;
                col = j;
                isEmpty = true;
                break;
            }
        }
        if (isEmpty) {
            break;
        }
    }

    // Base case: No empty cell left, puzzle solved
    if (!isEmpty) {
        return true;
    }

    // 2. Try placing digits 1 to 9
    for (int num = 1; num <= 9; num++) {
        if (isValid(grid, row, col, num)) {
            grid[row][col] = num; // Place candidate

            // Recursively attempt to solve rest of the grid
            if (solveSudoku(grid)) {
                return true;
            }

            // Backtrack: Reset cell if path failed
            grid[row][col] = 0;
        }
    }

    return false; // Triggers backtracking in previous call
}

int main() {
    // Sample 9x9 Sudoku puzzle (0 represents empty cells)
    vector<vector<int>> grid = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    cout << "--- Unsolved Sudoku ---\n";
    printGrid(grid);
    cout << "\n";

    if (solveSudoku(grid)) {
        cout << "--- Solved Sudoku ---\n";
        printGrid(grid);
    } else {
        cout << "No solution exists for the given Sudoku.\n";
    }

    return 0;
}
