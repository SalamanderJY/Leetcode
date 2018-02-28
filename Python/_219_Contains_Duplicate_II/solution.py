class Solution:
    def containsNearbyDuplicate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        mapping = {}
        for i in range(0, len(nums)):
            if not nums[i] in mapping:
                mapping[nums[i]] = i
            elif (i - mapping[nums[i]]) <= k:
                return True
            else:
                mapping[nums[i]] = i
        return False
