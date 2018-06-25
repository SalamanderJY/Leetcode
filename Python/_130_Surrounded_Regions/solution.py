import queue

class Solution:
    def solve(self, board):
        """
        :type board: List[List[str]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        if len(board) == 0 or len(board[0]) == 0:
            return    
        for i in range(len(board[0])):
            self.fill(board, 0, i);
            self.fill(board, len(board) - 1, i);  
        for i in range(len(board)):
            self.fill(board, i, 0)
            self.fill(board, i, len(board[0]) - 1)
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] == '#':
                    board[i][j] = 'O'
                elif board[i][j] == 'O':
                    board[i][j] = 'X'
        
    def fill(self, board, i, j):
        if board[i][j] != 'O':
            return
        board[i][j] = '#'
        q = queue.Queue()
        index = i * len(board[0]) + j
        q.put(index)
        while not q.empty():
            index = q.get()
            row = index // len(board[0])
            col = index % len(board[0])
            if row - 1 >= 0 and board[row - 1][col] == 'O':
                board[row - 1][col] = '#'
                q.put((row - 1) * len(board[0]) + col)
            if row + 1 < len(board) and board[row + 1][col] == 'O':
                board[row + 1][col] = '#'
                q.put((row + 1) * len(board[0]) + col)
            if col - 1 >= 0 and board[row][col - 1] == 'O':
                board[row][col - 1] = '#'
                q.put(row * len(board[0]) + col - 1)
            if col + 1 < len(board[0]) and board[row][col + 1] == 'O':
                board[row][col + 1] = '#'
                q.put(row * len(board[0]) + col + 1)
