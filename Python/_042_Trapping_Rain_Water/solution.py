class Solution:
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        n = len(height)
        if n == 0:
            return 0
        rightmax = [0] * n
        leftmax = [0] * n
        value = height[n - 1]
        rightmax[n - 1] = value
        wall = 0
        for i in range(n - 1, -1, -1):
            if height[i] > value:
                value = height[i]
            rightmax[i] = value
            wall += height[i]  
        value = height[0]
        leftmax[0] = value
        for i in range(0, n):
            if height[i] > value:
                value = height[i]
            leftmax[i] = value
        water = 0
        for i in range(n):
             water += min(leftmax[i], rightmax[i])
        return water - wall