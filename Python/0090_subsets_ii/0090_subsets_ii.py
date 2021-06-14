class Solution:
    def subsetsWithDup(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = []
        nums = sorted(nums)
        self.backtracking([], nums, res)
        return res
               
    def backtracking(self, solution , nums, res):
        res.append(solution)
        if not nums:
            return
        for i in range(len(nums)):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            temp = solution + [nums[i]]
            self.backtracking(temp, nums[i + 1:], res)
