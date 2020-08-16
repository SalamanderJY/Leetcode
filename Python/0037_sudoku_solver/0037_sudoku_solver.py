class Solution:
    def solveSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        def isValid(i, j):
            for col in range(9):
                if col != j and board[i][j] == board[i][col]:
                    return False
            for row in range(9):
                if row != i and board[i][j] == board[row][j]:
                    return False
            for row in range(i // 3 * 3, i // 3 * 3 + 3):
                for col in range(j // 3 * 3, j // 3 * 3 + 3):
                    if (row != i or col != j) and board[i][j] == board[row][col]:
                        return False
            return True
        
        def solveSudokuDFS(board):
            for i in range(9):
                for j in range(9):
                    if board[i][j] == '.':
                        for k in '123456789':
                            board[i][j] = k
                            if isValid(i, j) and solveSudokuDFS(board):
                                return True
                            board[i][j] = '.'
                        return False
            return True
        
        solveSudokuDFS(board)

