/**
 * Author: Sahil Chhabra (https://www.geeksforgeeks.org/printing-solutions-n-queen-problem/) 
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Solution counter
int counter;

/**
 * A utility function to check if a queen can be placed on board[row][col]. Note that this 
 * function is called when "col" queens are already placed in columns from 0 to col -1. 
 * So we need to check only left side for attacking queens
 */
bool isSafe(int N, int board[N][N], int row, int col) {
    int i, j;

    /* Check this row on left side */
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    /* Check upper diagonal on left side */
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    /* Check lower diagonal on left side */
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

/**
 *  A recursive utility function to solve N Queen problem
 */
int solveNQUtil(int N, int board[N][N], int col) {
    // All queens are placed
    if (col == N) {
        return ++counter;
    }

    // Consider this column and try placing this queen in all rows one by one
    for (int i = 0; i < N; i++) {
        // Check if queen can be placed on board[i][col]
        if (isSafe(N, board, i, col)) {
            // Place this queen in board[i][col]
            board[i][col] = 1;

            solveNQUtil(N, board, col + 1);

            // Doesn't lead to a solution do Backtrack
            board[i][col] = 0;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Argument missing! ./NQueensSerial n\n");
        return EXIT_FAILURE;
    }

    // Get size of array
    int n = atoi(argv[argc - 1]);
    if (n <= 0 || n > 27) {
        fprintf(stderr, "Invalid input! Size must between 0 and 27.\n");
        return EXIT_FAILURE;
    }

    // Init board
    int board[n][n];
    memset(board, 0, sizeof(board));

    // Calculate
    solveNQUtil(n, board, 0);
    printf("There are %d possible solutions\n", counter);

    return EXIT_SUCCESS;
}