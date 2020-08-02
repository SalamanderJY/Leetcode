·class Solution:
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        if len(nums) == 0:
            return -1
        left = 0
        right = len(nums) - 1
        while left + 1 < right:
            if nums[left] == target: return left
            if nums[right] == target: return right
            mid = left + (right - left) // 2
            if nums[mid] == target:
                return mid
            if nums[mid] < target:
                if (target < nums[right]) or (target > nums[right] and nums[mid] > nums[right]):
                    left = mid
                else: right = mid
            elif nums[mid] > target:
                if (target > nums[left]) or (target < nums[left] and nums[mid] < nums[left]):
                    right = mid
                else: left = mid
        if nums[left] == target: return left
        if nums[right] == target: return right
        return -1
