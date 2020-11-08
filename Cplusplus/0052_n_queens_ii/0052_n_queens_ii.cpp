class Solution {
private:
int g_solutionsNum = 0;

void backtracking(int n, int row, vector<string>& chessboard) {
    if (row == n) {
        g_solutionsNum++;
        return;
    }
    for (int col = 0; col < n; col++) {
        if (isValid(row, col, chessboard, n)) {
            chessboard[row][col] = 'Q';
            backtracking(n, row + 1, chessboard);
            chessboard[row][col] = '.';
        }
    }
}

bool isValid(int row, int col, vector<string>& chessboard, int n) {
    int count = 0;
    // check out column
    for (int i = 0; i < row; i++) { 
        if (chessboard[i][col] == 'Q') {
            return false;
        }
    }
    // check out 45 angle
    for (int i = row - 1, j = col - 1; i >=0 && j >= 0; i--, j--) {
        if (chessboard[i][j] == 'Q') {
            return false;
        }
    }
    // check out 135 angle
    for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (chessboard[i][j] == 'Q') {
            return false;
        }
    }
    return true;
}

public:
    int totalNQueens(int n) {
        std::vector<std::string> chessboard(n, std::string(n, '.'));
        backtracking(n, 0, chessboard);
        return g_solutionsNum;
    }
};
