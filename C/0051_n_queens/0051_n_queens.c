int g_solutionsSize = 0;

char** generateBoard(int* queens, int n)
{
    char** board = (char **)malloc(sizeof(char *) * n);
    for (int i = 0; i < n; i++) {
        board[i] = (char *)malloc(sizeof(char) * (n + 1));
        for (int j = 0; j < n; j++) {
            board[i][j] = '.';
        }
        board[i][queens[i]] = 'Q';
        board[i][n] = '\0';
    }
    return board;
}


void backtrack(char*** solutions, int* queens, int n, int row, int* columns, int* diagonals1, int* diagonals2)
{
    if (row == n) {
        char **board = generateBoard(queens, n);
        solutions[g_solutionsSize++] = board;
    }
    else {
        for (int i = 0; i < n; i++) {
            if (columns[i]) {
                continue;
            }
            /* row index - col index + n - 1, ensure it is larger than 0 */
            int diagonal1 = row - i + n - 1;
            if (diagonals1[diagonal1]) {
                continue;
            }
            /* row index + col index, ensure it is larger than 0 */
            int diagonal2 = row + i;
            if (diagonals2[diagonal2]) {
                continue;
            }
            queens[row] = i;
            columns[i] = true;
            diagonals1[diagonal1] = true;
            diagonals2[diagonal2] = true;

            backtrack(solutions, queens, n, row + 1, columns, diagonals1, diagonals2);

            queens[row] = -1;
            columns[i] = false;
            diagonals1[diagonal1] = false;
            diagonals2[diagonal2] = false;
        }
    }
}


char*** solveNQueens(int n, int* returnSize, int** returnColumnSizes)
{
    char ***solutions = malloc(sizeof(char **) * 512);
    g_solutionsSize = 0;
    int queens[n];
    int columns[n];
    /* diagonals at one direction */
    int diagonals1[n + n];
    /* diagonals at another direction */
    int diagonals2[n + n];
    memset(queens, -1, sizeof(queens));
    memset(columns, 0, sizeof(columns));
    memset(diagonals1, 0, sizeof(diagonals1));
    memset(diagonals2, 0, sizeof(diagonals2));

    backtrack(solutions, queens, n, 0, columns, diagonals1, diagonals2);

    *returnSize = g_solutionsSize;
    *returnColumnSizes = malloc(sizeof(int *) * g_solutionsSize);
    for (int i = 0; i < g_solutionsSize; i++) {
        (*returnColumnSizes)[i] = n;
    }
    return solutions;
}