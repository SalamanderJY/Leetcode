class Solution:
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = []
        self.backtracking([], nums, res)
        return res
               
    def backtracking(self, solution , nums, res):
        res.append(solution)
        if not nums:
            return
        for i in range(len(nums)):
            temp = solution + [nums[i]]
            self.backtracking(temp, nums[i + 1:], res)
