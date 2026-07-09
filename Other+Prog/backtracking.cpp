#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Helper function to check if it's safe to place a queen at board[row][col]
bool isSafe(int row, int col, const vector<string>& board, int n) {
    // Check upper column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q') return false;
    }

    // Check upper-left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') return false;
    }

    // Check upper-right diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q') return false;
    }

    return true;
}

// Core Backtracking Function
void solveNQueens(int row, vector<string>& board, vector<vector<string>>& solutions, int n) {
    // Base Case: If all queens are placed, save the solution
    if (row == n) {
        solutions.push_back(board);
        return;
    }

    // Try placing a queen in all columns of the current row
    for (int col = 0; col < n; col++) {
        if (isSafe(row, col, board, n)) {
            
            // 1. Make the move (Choose)
            board[row][col] = 'Q';

            // 2. Explore further rows with this choice
            solveNQueens(row + 1, board, solutions, n);

            // 3. Undo the move (Backtrack)
            board[row][col] = '.'; 
        }
    }
}

int main() {
    int n = 4; // Change this for different board sizes (e.g., 8)
    
    // Initialize an empty board filled with '.'
    vector<string> board(n, string(n, '.'));
    vector<vector<string>> solutions;

    solveNQueens(0, board, solutions, n);

    // Print all found solutions
    cout << "Total solutions for " << n << "-Queens: " << solutions.size() << "\n\n";
    for (int i = 0; i < solutions.size(); i++) {
        cout << "Solution " << i + 1 << ":\n";
        for (const string& row : solutions[i]) {
            cout << row << "\n";
        }
        cout << "\n-----------------\n\n";
    }

    return 0;
}
