package backtracking;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Subsets {
    public static List<List<Integer>> subsets(int[] nums) {
        ArrayList<Integer> list = new ArrayList<Integer>();
        ArrayList solution = new ArrayList<ArrayList<Integer>>();
        
        if(nums.length == 0) {
        	solution.add(list);
        	return solution;
        }
        
        Arrays.sort(nums);
        
        BackTracking(solution, list, nums, 0);
        
        return solution;
    }
    
    public static void BackTracking(ArrayList<ArrayList<Integer>> solution, ArrayList<Integer> list,
    		int[] nums, int pos) {
    	solution.add(new ArrayList<Integer>(list));
    	
    	for(int i = pos; i < nums.length; i++){
    		list.add(nums[i]);
    		
    		BackTracking(solution, list, nums, i+1);
    		list.remove(list.size()-1);
    	}
    }
    
    public static void main(String[] args) {
    	List solution = new ArrayList<ArrayList<Integer>>();
    	int[] nums = {};
    	solution = subsets(nums);
    	System.out.println(solution);
	}
}
