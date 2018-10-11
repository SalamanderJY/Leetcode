class Solution {
    public void nextPermutation(int[] nums) {
        int i;
        for (i = nums.length - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) 
                break;
        }    
        for (int j = i + 1; j < (nums.length + i + 1) / 2; j++) {
            int temp = nums[j];
            nums[j] = nums[nums.length + i - j];
            nums[nums.length + i - j] = temp;
        }
        if (i == -1) return;
        for (int j = i + 1; j < nums.length; j++)
            if (nums[j] > nums[i]) {
                int temp = nums[j];
                nums[j] = nums[i];
                nums[i] = temp;
                break;
            }
    }
}
