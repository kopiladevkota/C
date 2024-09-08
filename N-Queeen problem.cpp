#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define N 4 // Define the size of the chessboard

int board[N][N]; // Chessboard representation

// Function to print the board
void printBoard() {
    printf("Solution:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a queen can be placed at board[row][col]
bool isSafe(int row, int col) {
    int i, j;

    // Check this row on left side
    for (i = 0; i < col; i++) {
        if (board[row][i]) {
            return false;
        }
    }

    // Check upper diagonal on left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    // Check lower diagonal on left side
    for (i = row, j = col; j >= 0 && i < N; i++, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    return true;
}

// Recursive function to solve N-Queens problem using backtracking
bool solveNQueens(int col) {
    // Base case: If all queens are placed, return true
    if (col >= N) {
        return true;
    }

    // Try placing a queen in each row of the current column
    for (int i = 0; i < N; i++) {
        // Check if the queen can be placed on board[i][col]
        if (isSafe(i, col)) {
            // Place the queen
            board[i][col] = 1;

            // Recursively solve for the next column
            if (solveNQueens(col + 1)) {
                return true;
            }

            // Backtrack: If placing queen doesn't lead to a solution, remove it
            board[i][col] = 0;
        }
    }

    // If no queen can be placed in this column, return false
    return false;
}

// Main function to initialize board and solve N-Queens problem
int main() {
    // Initialize board with all zeros (no queens initially placed)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = 0;
        }
    }

    // Solve the N-Queens problem starting from the first column
    if (solveNQueens(0)) {
        printBoard();
    } else {
        printf("Solution does not exist for N = %d\n", N);
    }

    return 0;
}
