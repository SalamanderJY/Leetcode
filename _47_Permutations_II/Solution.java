package _47_Permutations_II;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Set;


public class Solution {
	
     public List<List<Integer>> permuteUnique(int[] nums) {
    	 List<List<Integer>> result = new ArrayList<List<Integer>>();
    	 if (nums.length == 0) {
             return result;
         }
    	 Arrays.sort(nums);
         int index = 0;
         List<Integer> sub = new ArrayList<Integer>();
         Permutation(nums, index, sub, result);
         return result;
	    
     }
     
     public void Permutation(int[] nums, int index, List<Integer> sub, List<List<Integer>> result) {
    	 if(index == nums.length) {
    		 //已经递归到一个完整子集
    		 result.add(sub);
    		 return ;
    	 }
    	 
    	 Set<Integer> appearred = new HashSet<Integer>();
    	 for(int i = index; i < nums.length; i++) {
    		 if(appearred.contains(nums[i])){
    			 //跳出循环，遇到相同数字已经遍历过
    			 continue;
    		 }
    		 
    		 appearred.add(nums[i]);
    		 Swap(nums, i, index);
    		 
    		 List<Integer> copy = new ArrayList<Integer>(sub);
             copy.add(nums[index]);
             
             Permutation(nums, index+1, copy, result);
             
             Swap(nums, index, i);
    		 
    	 }
     }
	 
     public void Swap(int[] nums, int a, int b) {
    	 if(a < nums.length && b < nums.length) {
             int temp = nums[a];
             nums[a] = nums[b];
             nums[b] = temp;
    	 }
     }
}
