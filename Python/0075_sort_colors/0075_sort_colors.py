class Solution:
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        red = 0
        white = 0
        blue = 0
        for i in range(len(nums)):
            if nums[i] == 0:
                red += 1
            elif nums[i] == 1:
                white += 1
            else:
                blue += 1
        for i in range(len(nums)):
            if red > 0:
                nums[i] = 0
                red -= 1
                continue
            if white > 0:
                nums[i] = 1
                white -= 1
                continue
            if blue > 0:
                nums[i] = 2
                blue -= 1
                continue
