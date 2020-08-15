bool isValidSudoku(char** board, int boardSize, int* boardColSize)
{
    int *row = malloc(sizeof(int) * 10);
    int *col = malloc(sizeof(int) * 10);
    int *num = malloc(sizeof(int) * 10);
    for (int i = 0; i < boardSize; i++) {
        memset(row, 0, 10 * sizeof(int));
        memset(col, 0, 10 * sizeof(int));
        // check row and col
        for (int j = 0; j < boardSize; j++) {
            if (board[i][j] != '.') {
                if (row[(board[i][j] - '0')])
                    return false;
                row[(board[i][j] - '0')] = true;
            } 
            if (board[j][i] != '.') {
                if (col[(board[j][i] - '0')])
                    return false;
                col[(board[j][i] - '0')] = true;
            }
        }
        // check 3 x 3 block
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                memset(num, 0, sizeof(int) * 10);
                for (int m = 3 * i; m < 3 * i + 3; m++) {
                    for (int n = 3 * j; n < 3 * j + 3; n++) {
                        if (board[m][n] != '.') {
                            if (num[board[m][n] - '0'])
                                return false;
                            num[board[m][n] - '0'] = true;
                        }
                    }
                }
            }
        }    
    }
    free(row);
    free(col);
    free(num);
    return true;
}