package _229_Majority_Element_II;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;

public class Solution {
	public List<Integer> majorityElement(int[] nums) {
        List<Integer> list = new ArrayList<Integer>();
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        for(int i = 0; i < nums.length; i++) {
        	if(map.containsKey(nums[i])){
        		map.put(nums[i], map.get(nums[i])+ 1);
        	}
        	else {
        		map.put(nums[i], 1);
        	}
        }
        
        for ( Entry<Integer, Integer> entry : map.entrySet() ) {         	  
            if(entry.getValue() > nums.length / 3){
            	list.add(entry.getKey());
            }
        } 
        return list;
    }
}
