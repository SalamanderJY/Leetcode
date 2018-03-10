class NumArray {
    
    private int[] currentSum;

    public NumArray(int[] nums) {
        currentSum = new int[nums.length + 1];
        currentSum[0] = 0;
        for (int i = 1; i < nums.length + 1; i++)
            currentSum[i] = currentSum[i - 1] + nums[i - 1];     
    }
    
    public int sumRange(int i, int j) {
        return currentSum[j + 1] - currentSum[i];
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */