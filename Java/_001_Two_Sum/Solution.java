package _1_Two_Sum;

import java.util.HashMap;
import java.util.Map;

public class Solution {
    public int[] twoSum(int[] nums, int target) {
	Map<Integer, Integer> map = new HashMap<Integer, Integer>();
	int[] result = {};
	for (int i = 0; i < nums.length; i++) {
	    // add i-th number
            Integer a = map.get(nums[i]);
            if (a == null)
                map.put(nums[i], i);
            // find (target - numbers[i])
            a = map.get(target - nums[i]);
            if (a != null && a < i) 
		result = new int[]{a, i};
                break;
            }
	}	
    	return result;      
    }
}
