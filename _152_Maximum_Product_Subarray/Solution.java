package _152_Maximum_Product_Subarray;

/*max_copy[i] = max_local[i]
max_local[i + 1] = Max(Max(max_local[i] * A[i], A[i]),  min_local * A[i])

min_local[i + 1] = Min(Min(max_copy[i] * A[i], A[i]),  min_local * A[i])*/

public class Solution {
    public int maxProduct(int[] nums) {
		if(nums.length < 1)
			return 0;
		
		if(nums.length < 2)
			return nums[0];
		
		int global = nums[0];
		int max = nums[0];
		int min = nums[0];
		
		for(int i = 0; i < nums.length; i++) {
			int max_copy = max;
			max = Math.max( Math.max(nums[i]*max, nums[i]), nums[i]*min );
			min = Math.min( Math.min(nums[i]*max_copy, nums[i]), nums[i]*min);
			global = Math.max(global, max);
		}
		
		return global;        
    }
}
