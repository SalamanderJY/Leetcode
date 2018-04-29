class Solution:
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        consider = len(nums) - 2
        while consider >= 0:
            if nums[consider] < nums[consider + 1]: 
                break
            consider -= 1
        for j in range(consider + 1, (len(nums) + consider + 1) // 2):
            nums[j], nums[len(nums) + consider - j] = nums[len(nums) + consider - j], nums[j]
        if consider == -1: return
        for j in range(consider + 1, len(nums)):
            if nums[j] > nums[consider]:
                nums[j], nums[consider] = nums[consider], nums[j]
                break

