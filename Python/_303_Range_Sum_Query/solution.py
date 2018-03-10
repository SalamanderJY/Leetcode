class NumArray:

    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.currentSum = []
        self.currentSum.append(0)
        for i in range(0, len(nums)):
            self.currentSum.append(self.currentSum[i] + nums[i])

    def sumRange(self, i, j):
        """
        :type i: int
        :type j: int
        :rtype: int
        """
        return self.currentSum[j + 1] - self.currentSum[i];

# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(i,j)