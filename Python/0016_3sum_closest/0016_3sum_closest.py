class Solution:
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        nums = sorted(nums)
        total = nums[0] + nums[1] + nums[len(nums) - 1]
        closestSum = total
        for i in range(0, len(nums) - 2):
            if i == 0 or nums[i] != nums[i - 1]:
                left = i + 1
                right = len(nums) - 1
                while left < right:
                    total = nums[left] + nums[right] + nums[i]
                    if total < target:
                        while left < right and nums[left] == nums[left + 1]:
                            left += 1
                        left += 1
                    elif total > target:
                        while left < right and nums[right] == nums[right - 1]:
                            right -= 1
                        right -= 1
                    else: return total
                    if abs(total - target) < abs(closestSum - target):
                        closestSum = total
        return closestSum

