int isValid(char** board, int i, int j)
{
    for (int row = 0; row < 9; row++) {
        if (row != i && board[i][j] == board[row][j]) {
            return 0;
        }
    }
    for (int col = 0; col < 9; col++) {
        if (col != j && board[i][j] == board[i][col]) {
            return 0;
        }
    }
    for (int row = i / 3 * 3; row < i / 3 * 3 + 3; row++) {
        for (int col = j / 3 * 3; col < j / 3 * 3 + 3; col++) {
            if ((row != i || col != j) && board[i][j] == board[row][col]) {
                return 0;
            }
        }
    }
    return 1;
}

int solveSudokuDFS(char** board, int i, int j) 
{
    if (i == 9) {
        return 1;
    }
    if (j == 9) {
        return solveSudokuDFS(board, i + 1, 0);
    }
    if (board[i][j] == '.') {
        for (int k = 1; k < 10; k++) {
            board[i][j] = (char)(k + '0');
            if (isValid(board, i, j)) {
                if (solveSudokuDFS(board, i, j + 1)) {
                    return 1;
                }
            }
            board[i][j] = '.';
        }
    }
    else {
        return solveSudokuDFS(board, i, j + 1);
    }
    return 0;
}

void solveSudoku(char** board, int boardSize, int* boardColSize)
{
    if (board == NULL || boardSize != 9 || boardColSize[0] != 9 ) {
        return ;
    }
    solveSudokuDFS(board, 0, 0);
    return ;
}