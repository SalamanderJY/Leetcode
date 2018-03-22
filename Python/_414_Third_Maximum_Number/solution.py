import math

class Solution:
    def thirdMax(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums = set(nums)
        one = two = three = -math.inf
        for i in nums:
            if i > one:
                one, two, three = i, one, two
            elif i > two and i < one:
                two, three = i, two
            elif i > three and i < two:
                three = i
        return three if len(nums) >= 3 else one
