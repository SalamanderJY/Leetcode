class Solution:
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = 0
        for i in range(0, 32):
            count = 0
            for j in range(len(nums)):
                count += (nums[j] >> i) & 1
            result |= (count % 3) << i
        if result >= 2**31:
            result -= 2**32 
        return result
