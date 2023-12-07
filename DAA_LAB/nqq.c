#include <stdio.h>
#include <stdbool.h>

#define N 4 // Change this to the desired board size

void printSolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%2d ", board[i][j]);
        printf("\n");
    }
    printf("\n");
}

bool isSafe(int board[N][N], int row, int col) {
    // Check for queens in the same row
    for (int i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // Check for queens in the upper diagonal on the left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check for queens in the lower diagonal on the left side
    for (int i = row, j = col; i < N && j >= 0; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQueensUtil(int board[N][N], int col) {
    if (col == N) {
        // All queens are placed successfully
        printSolution(board);
        return true;
    }

    bool res = false;
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1; // Place queen

            // Recur to place the rest of the queens
            res = solveNQueensUtil(board, col + 1) || res;

            // If placing queen in board[i][col] doesn't lead to a solution,
            // then remove the queen from the board[i][col]
            board[i][col] = 0; // Backtrack
        }
    }

    return res;
}

void solveNQueens() {
    int board[N][N] = {0};

    if (!solveNQueensUtil(board, 0))
        printf("Solution does not exist");
}

int main() {
    solveNQueens();
    return 0;
}


