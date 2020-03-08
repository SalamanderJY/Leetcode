class Solution:
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        # Two Pointers Traverse
        left, right, maximum = 0, len(height) - 1, 0
        while left < right:
            maximum = max(maximum, min(height[left], height[right]) * (right - left))
            if height[left] < height[right]:
                left += 1
            else:
                right -= 1
        return maximum
