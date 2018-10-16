class Solution:
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        # check row and col
        for i in range(len(board)):
            row = [False] * 10
            col = [False] * 10
            for j in range(len(board)):
                if board[i][j] != '.':
                    if row[ord(board[i][j]) - ord('0')]:
                        return False
                    row[ord(board[i][j]) - ord('0')] = True         
                if board[j][i] != '.':
                    if (col[ord(board[j][i]) - ord('0')]):
                        return False
                    col[ord(board[j][i]) - ord('0')] = True
        # check 3 x 3 block
        for i in range(3):
            for j in range(3):
                num = [False] * 10
                for row in range(i * 3, i * 3 + 3):
                    for col in range(j * 3, j * 3 + 3):
                        if board[row][col] != '.':
                            if (num[ord(board[row][col]) - ord('0')]):
                                return False
                            num[ord(board[row][col]) - ord('0')] = True
        return True

