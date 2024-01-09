#include <stdio.h>
#include <stdbool.h>

#define MAX_N 100 // Adjust the maximum allowed board size if needed

void printSolution(int board[][MAX_N], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", board[i][j] ? 'Q' : '.');
        }
        printf("\n");
    }
    printf("\n");
}

bool a(int board[][MAX_N], int row, int col, int N) {
    for (int i = 0; i < col; i++) {
        if (board[row][i]) {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    for (int i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    return true;
}

bool b(int board[][MAX_N], int col, int N) {
    if (col >= N) {
        printSolution(board, N);
        return true;
    }

    bool res = false;
    for (int i = 0; i < N; i++) {
        if (a(board, i, col, N)) {
            board[i][col] = 1;
            res = b(board, col + 1, N) || res;
            board[i][col] = 0;
        }
    }

    return res;
}

void c(int N) {
    int board[MAX_N][MAX_N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = 0;
        }
    }

    if (!b(board, 0, N)) {
        printf("Solution does not exist\n");
    }
}

int main() {
    int N;
    printf("Enter the size of the chessboard (N): ");
    scanf("%d", &N);

    if (N <= 0 || N > MAX_N) {
        printf("Invalid board size. Please choose a value between 1 and %d\n", MAX_N);
        return 1;
    }

    c(N);

    return 0;
}



