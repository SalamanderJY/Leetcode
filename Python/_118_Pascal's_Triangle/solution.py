class Solution:
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        if numRows == 0:
            return []
        else:
            result = []
            firstlayer = [1]
            result.append(firstlayer)
            for _ in range(0, numRows - 1):
                firstlayer = self.singlelayer(firstlayer)
                result.append(firstlayer)
            return result
        
    def singlelayer(self, prelayer):
        nextlayer = []
        nextlayer.append(1)
        for i in range(0, len(prelayer) - 1):
            nextlayer.append(prelayer[i] + prelayer[i + 1])
        nextlayer.append(1)
        return nextlayer
