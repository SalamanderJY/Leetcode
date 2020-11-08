int g_solutionsNum = 0;

void backtrack(int* queens, int n, int row, int* columns, int* diagonals1, int* diagonals2)
{
    if (row == n) {
        g_solutionsNum++;
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

            backtrack(queens, n, row + 1, columns, diagonals1, diagonals2);

            queens[row] = -1;
            columns[i] = false;
            diagonals1[diagonal1] = false;
            diagonals2[diagonal2] = false;
        }
    }
}


int totalNQueens(int n)
{
    g_solutionsNum = 0;
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

    backtrack(queens, n, 0, columns, diagonals1, diagonals2);

    return g_solutionsNum;
}