class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0 || board[0].size() == 0)  
            return false;  
        int m = board.size(), n = board[0].size();    
        vector<vector<bool>> visited(m, vector<bool>(n, false));    
        for(int i = 0; i < m; i++)    
            for(int j = 0; j < n; j++)    
                if(dfs(board, visited, word, i, j, 0))   
                    return true;    
        return false; 
    }
    
    bool dfs(vector<vector<char>> &board, vector<vector<bool>> &visited, string &word, int x, int y, int k) {  
        if (k >= word.size())  
            return true;  
        int m = board.size(), n = board[0].size();  
        if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y] || board[x][y] != word[k])  
            return false;  
        visited[x][y] = true;  
        if (dfs(board, visited, word, x + 1, y, k + 1))  
            return true;  
        if (dfs(board, visited, word, x - 1, y, k + 1))  
            return true;  
        if (dfs(board, visited, word, x, y + 1, k + 1))  
            return true;  
        if (dfs(board, visited, word, x, y - 1, k + 1))  
            return true;  
        visited[x][y] = false;  
        return false;
    }
};