class Solution:
    def grayCode(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        # Gray Code = i ^ (i >> 1)
        result = []
        for i in range(2 ** n):
            result.append(i ^ (i >> 1))
        return result
