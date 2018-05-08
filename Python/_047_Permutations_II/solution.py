class Solution:
    def __init__(self):
        self.res = []
    
    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if len(nums) == 0:
            return self.res
        nums = sorted(nums)
        self.permutation(self.res, nums, 0)
        return self.res
    
    def permutation(self, res, nums, pos):
        if pos == len(nums):
            temp = []
            for n in nums:
                temp.append(n)
            self.res.append(temp)
        else:
            appear = set()
            for i in range(pos, len(nums)):
                if not nums[i] in appear:
                    appear.add(nums[i])
                    nums[i], nums[pos] = nums[pos], nums[i]
                    self.permutation(self.res, nums, pos + 1)
                    nums[i], nums[pos] = nums[pos], nums[i]

