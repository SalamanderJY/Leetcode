class Solution:
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = []
        if len(nums) == 0:
            return res
        nums = sorted(nums)
        mapping = {}
        for i in range(0, len(nums)):
            mapping[nums[i]] = i
        
        for i in range(0, len(nums) - 2):
            if nums[i] > 0: 
                return res
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            for j in range(i + 1, len(nums) - 1):
                if j - 1 > i and nums[j] == nums[j - 1]:
                    continue
                two = nums[i] + nums[j]
                if -two < nums[j]: 
                    break
                if two > 0:
                    return res
                # exists and not traverse
                if -two in mapping and mapping[-two] > j:
                    temp = []
                    temp.append(nums[i])
                    temp.append(nums[j])
                    temp.append(-two)
                    res.append(temp)
        return res

