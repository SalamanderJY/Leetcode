class Solution {
    public boolean canJump(int[] nums) {
        int maximum = nums[0];
        int index = 0;
        while (index <= maximum && index < nums.length) {
            if (index + nums[index] > maximum)
                maximum = index + nums[index];
            index++;
        }
        return maximum >= nums.length - 1 ? true : false;
    }
}
