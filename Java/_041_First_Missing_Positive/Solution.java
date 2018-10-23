class Solution {
    public int firstMissingPositive(int[] nums) {
        if (nums.length == 0)
            return 1;
        int[] newNums = new int[nums.length + 1];
		System.arraycopy(nums, 0, newNums, 0, nums.length);
        newNums[nums.length] = 0;
        for (int i = 0; i < newNums.length; i++) {
            if (newNums[i] < 0 || newNums[i] >= newNums.length)
                newNums[i] = 0;
        }
        for (int i = 0; i < newNums.length; i++) {
            newNums[newNums[i] % newNums.length] += newNums.length;
        }
        for (int i = 1; i < newNums.length; i++) {
            if (newNums[i] / newNums.length == 0)
                return i;
        }
        return newNums.length;
    }
}