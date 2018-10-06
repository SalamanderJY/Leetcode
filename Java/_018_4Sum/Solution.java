class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        if (nums.length == 0)
            return res;
        // sort the array
        Arrays.sort(nums);
        // hash map
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        for (int i = 0; i < nums.length; i++)
            map.put(nums[i], i);
        
        for (int i = 0; i < nums.length - 3; i++) {
            if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) 
                return res;
            if (nums[i] + nums[nums.length - 1] + nums[nums.length - 2] + nums[nums.length - 3] < target)
                continue;    
            if (i > 0 && nums[i] == nums[i - 1]) 
                continue;
            for (int j = i + 1; j < nums.length - 2; j++) {
                if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target)
                    break;
                if (nums[i] + nums[j] + nums[nums.length - 1] + nums[nums.length - 2] < target)
                    continue;
                if (j - 1 > i && nums[j] == nums[j - 1]) 
                    continue;
                for (int k = j + 1; k < nums.length - 1; k++) {
                    if (k - 1 > j && nums[k] == nums[k - 1])
                        continue;
                    int three = nums[i] + nums[j] + nums[k];
                    if (map.containsKey(target - three) && map.get(target - three) > k) {
                        List<Integer> temp = new ArrayList<Integer>();
                        temp.add(nums[i]);
                        temp.add(nums[j]);
                        temp.add(nums[k]);
                        temp.add(target - three);
                        res.add(temp);
                    }   
                }
            }
        }
        return res;
    }
}
