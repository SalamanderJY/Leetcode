class Solution:
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        res = []
        if len(nums) == 0:
            return res
        nums = sorted(nums)
        mapping = {}
        for i in range(0, len(nums)):
            mapping[nums[i]] = i
        for i in range(0, len(nums) - 3):
            if nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target: 
                return res
            if nums[i] + nums[len(nums) - 1] + nums[len(nums) - 2] + nums[len(nums) - 3] < target:
                continue
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            for j in range(i + 1, len(nums) - 2):
                if nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target:
                    break
                if nums[i] + nums[j] + nums[len(nums) - 1] + nums[len(nums) - 2] < target:
                    continue
                if j - 1 > i and nums[j] == nums[j - 1]:
                    continue   
                for k in range(j + 1, len(nums) - 1):
                    if k - 1 > j and nums[k] == nums[k - 1]:
                        continue
                    three = nums[i] + nums[j] + nums[k]
                    # exists and not traverse
                    if target - three in mapping and mapping[target - three] > k:
                        temp = []
                        temp.append(nums[i])
                        temp.append(nums[j])
                        temp.append(nums[k])
                        temp.append(target - three)
                        res.append(temp)
        return res
