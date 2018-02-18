class Solution:
    def getRow(self, rowIndex):
        """
        :type rowIndex: int
        :rtype: List[int]
        """
        curRow = []
        if rowIndex < 0:
            return curRow

        curRow.append(1)
        for row in range(0, rowIndex):
            curRow.append(1)
            for i in range(1, row + 1)[::-1]:
                curRow[i] = curRow[i] + curRow[i - 1]
        return curRow
