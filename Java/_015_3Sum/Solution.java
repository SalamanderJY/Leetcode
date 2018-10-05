class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        if (nums.length == 0)
            return res;
        // sort the array
        Arrays.sort(nums);
        // hash map
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        for (int i = 0; i < nums.length; i++)
            map.put(nums[i], i);
        
        for (int i = 0; i < nums.length - 2; i++) {
            if (nums[i] > 0) 
                return res;
            if (i > 0 && nums[i] == nums[i - 1]) 
                continue;
            for (int j = i + 1; j < nums.length - 1; j++) {
                if (j - 1 > i && nums[j] == nums[j - 1]) 
                    continue;
                int two = nums[i] + nums[j];
                if (-two < nums[j]) 
                    break;
                if (two > 0) 
                    return res;
                // exists and not traverse
                if (map.containsKey(-two) && map.get(-two) > j) {
                    List<Integer> temp = new ArrayList<Integer>();
                    temp.add(nums[i]);
                    temp.add(nums[j]);
                    temp.add(-two);
                    res.add(temp);
                }
            }
        }
        return res;
    }
}
