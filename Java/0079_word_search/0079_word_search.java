class Solution {
    public boolean exist(char[][] board, String word) {
        if (board.length == 0 || board[0].length == 0)  
            return false;  
        int m = board.length, n = board[0].length;    
        boolean[][] visited = new boolean[m][n];    
        for (int i = 0; i < m; i++)    
            for (int j = 0; j < n; j++)    
                if (dfs(board, visited, word, i, j, 0))   
                    return true;    
        return false; 
    }
    
    public boolean dfs(char[][] board, boolean[][] visited, String word, int x, int y, int k) {  
        if (k >= word.length())  
            return true;  
        int m = board.length, n = board[0].length;  
        if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y] || board[x][y] != word.charAt(k))  
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
}