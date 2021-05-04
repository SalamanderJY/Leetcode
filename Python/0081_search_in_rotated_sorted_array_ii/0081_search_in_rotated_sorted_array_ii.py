class Solution:
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: bool
        """
        
        if len(nums) == 0:
            return False
        left = 0
        right = len(nums) - 1
        while left + 1 < right:
            if nums[left] == target: 
                return True
            if nums[right] == target: 
                return True
            mid = left + (right - left) // 2
            if nums[mid] == target:
                return True
            if nums[left] < nums[mid]:
                if target < nums[left] or target > nums[mid]:
                    left = mid
                else: 
                    right = mid
            elif nums[left] > nums[mid]:
                if target < nums[mid] or target > nums[right]:
                    right = mid
                else: 
                    left = mid
            else:
                left += 1
        if nums[left] == target: 
            return True
        if nums[right] == target: 
            return True
        return False