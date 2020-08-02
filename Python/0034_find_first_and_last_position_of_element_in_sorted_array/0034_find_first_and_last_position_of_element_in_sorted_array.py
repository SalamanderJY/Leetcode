class Solution:
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        left = 0
        right = len(nums) - 1
        while left <= right:
            mid = left + (right - left) // 2
            if nums[mid] == target:
                left = right = mid
                while left >= 0 and nums[left] == nums[mid]:
                    left -= 1
                while right <= len(nums) - 1 and nums[right] == nums[mid]:
                    right += 1
                return [left + 1, right - 1]
            elif nums[mid] < target:
                left = mid + 1
            elif nums[mid] > target: 
                right = mid - 1
        return [-1, -1]
