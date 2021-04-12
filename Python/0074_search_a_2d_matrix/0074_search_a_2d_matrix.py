class Solution:
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        i = len(matrix) - 1
        j = 0
        while i >= 0 and j <= len(matrix[0]) - 1:
            if target > matrix[i][j]:
                j += 1
            elif target < matrix[i][j]:
                i -= 1;
            else:
                return True
        return False
