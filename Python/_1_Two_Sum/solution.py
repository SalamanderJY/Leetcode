class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        result = []
        hashmap = {}
        for i in range(0, len(nums)):
            numToFind = target - nums[i]
            if str(numToFind) in hashmap:
                result.append(hashmap.get(str(numToFind)))
                result.append(i)
                return result
            hashmap[str(nums[i])] = i
        return result

