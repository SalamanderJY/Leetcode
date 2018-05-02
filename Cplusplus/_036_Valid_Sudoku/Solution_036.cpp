class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++)
        {
            vector<bool> row(10, false);
            vector<bool> col(10, false);
            for (int j = 0; j < board.size(); j++)
            {
                if (board[i][j] != '.')
                {
                    if (row[board[i][j] - '0'])
                        return false;
                    row[board[i][j] - '0'] = true;
                }
                
                if (board[j][i] != '.')
                {
                    if (col[board[j][i] - '0'])
                        return false;
                    col[board[j][i] - '0'] = true;
                }
            }
        }
        
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                vector<bool> num(10, false);
                for (int row = 3 * i; row < 3 * i + 3; row++)
                {
                    for (int col = 3 * j; col < 3 * j + 3; col++)
                    {
                        if (board[row][col] != '.')
                        {
                            if (num[board[row][col] - '0'])
                                return false;
                            num[board[row][col] - '0'] = true;
                        }
                    }
                }
            }
        }
        return true;
    }
};
