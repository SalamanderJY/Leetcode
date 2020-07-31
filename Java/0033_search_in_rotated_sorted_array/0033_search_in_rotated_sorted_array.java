class Solution {
    public int search(int[] nums, int target) {
        if (nums.length == 0)
            return -1;
        int left = 0;
        int right = nums.length - 1;
        while (left + 1 < right) {
            if (nums[left] == target) 
                return left;
            if (nums[right] == target) 
                return right;
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] < target) {
                if ((target < nums[right]) || (target > nums[right] && nums[mid] > nums[right]))
                    left = mid;
                else 
                    right = mid;
            }
            else if (nums[mid] > target) {
                if ((target > nums[left]) || (target < nums[left] && nums[mid] < nums[left]))
                    right = mid;
                else 
                    left = mid;
            }
        }
        if (nums[left] == target) 
            return left;
        if (nums[right] == target) 
            return right;
        return -1;
    }
}
