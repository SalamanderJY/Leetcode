class Solution {
    public int maxArea(int[] height) {
        int left = 0, right = height.length - 1, maximum = 0;
        while (left < right) {
            maximum = Math.max(maximum, Math.min(height[left], height[right]) * (right - left));
            if (height[left] < height[right])
                left++;
            else
                right--;
        }
        return maximum;
    }
}