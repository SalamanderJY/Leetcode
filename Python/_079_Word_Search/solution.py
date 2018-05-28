class Solution:
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        if len(board) == 0 or len(board[0]) == 0:
            return False
        m = len(board)
        n = len(board[0])
        visited = [[False for i in range(n)] for j in range(m)]
        for i in range(m):
            for j in range(n):
                if self.dfs(board, visited, word, i, j, 0):
                    return True
        return False
              
    def dfs(self, board, visited, word, x, y, k):
        if k >= len(word):
            return True
        m = len(board)
        n = len(board[0])
        if x < 0 or x >= m or y < 0 or y >= n or visited[x][y] or board[x][y] != word[k]:
            return False
        visited[x][y] = True
        if self.dfs(board, visited, word, x + 1, y, k + 1):
            return True
        if self.dfs(board, visited, word, x - 1, y, k + 1):
            return True
        if self.dfs(board, visited, word, x, y + 1, k + 1):
            return True
        if self.dfs(board, visited, word, x, y - 1, k + 1):
            return True
        visited[x][y] = False
        return False
 