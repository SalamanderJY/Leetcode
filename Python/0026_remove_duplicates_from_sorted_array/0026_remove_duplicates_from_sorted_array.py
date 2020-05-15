class Solution:
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums[:] = collections.OrderedDict().fromkeys(nums)
        return len(nums)
        
