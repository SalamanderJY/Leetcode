class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0 || board[0].size() == 0)
            return;
        
        for (int i = 0; i < board[0].size(); i++) {
            fill(board, 0, i);
            fill(board, board.size() - 1, i);
        }   
        for (int i = 0; i < board.size(); i++) {
            fill(board, i, 0);
            fill(board, i, board[0].size() - 1);
        }
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '#')
                    board[i][j] = 'O';
                else if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
    
    void fill(vector<vector<char>>& board, int i, int j) {
        if (board[i][j] != 'O')
            return;
        board[i][j] = '#';
        queue<int> q;
        int index = i * board[0].size() + j;
        q.push(index);
        while (!q.empty()) {
            index = q.front();
            q.pop();
            int row = index / board[0].size();
            int col = index % board[0].size();
            if (row - 1 >= 0 && board[row - 1][col] == 'O') {
                board[row - 1][col] = '#';
                q.push((row - 1) * board[0].size() + col);
            }
            if (row + 1 < board.size() && board[row + 1][col] == 'O') {
                board[row + 1][col] = '#';
                q.push((row + 1) * board[0].size() + col);
            }
            if (col - 1 >= 0 && board[row][col - 1] == 'O') {
                board[row][col - 1] = '#';
                q.push(row * board[0].size() + col - 1);
            }
            if (col + 1 < board[0].size() && board[row][col + 1] == 'O') {
                board[row][col + 1] = '#';
                q.push(row * board[0].size() + col + 1);
            }
        }
    }
};