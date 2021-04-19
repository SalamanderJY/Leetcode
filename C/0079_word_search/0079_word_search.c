bool dfs(char** board, int boardSize, int* boardColSize, char* word , bool** visited, int x, int y, int len) {  
        if (len >= strlen(word))  
            return true;  
        int m = boardSize, n = boardColSize[0];   
        if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y] || board[x][y] != word[len])  
            return false;  
        visited[x][y] = true;  
        if (dfs(board, boardSize, boardColSize, word, visited, x + 1, y, len + 1))  
            return true;  
        if (dfs(board, boardSize, boardColSize, word, visited, x - 1, y, len + 1))  
            return true;  
        if (dfs(board, boardSize, boardColSize, word, visited, x, y + 1, len + 1))  
            return true;  
        if (dfs(board, boardSize, boardColSize, word, visited, x, y - 1, len + 1))  
            return true;  
        visited[x][y] = false;  
        return false;
    }

bool exist(char** board, int boardSize, int* boardColSize, char* word){
    if (boardSize == 0 || boardColSize[0] == 0)  
        return false;  
    int m = boardSize, n = boardColSize[0];    
    bool** visited = (bool **)malloc(sizeof(bool *) * m);
    for (int i = 0; i < m; i++) {
        visited[i] = (bool *)malloc(sizeof(bool) * n);
        for (int j = 0; j < n; j++) {
            visited[i][j] = false;
        }
    }
    for(int i = 0; i < m; i++)    
        for (int j = 0; j < n; j++)    
            if (dfs(board, boardSize, boardColSize, word, visited, i, j, 0))   
                return true;    
    return false; 
}