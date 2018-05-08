class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        if (nums.length == 0) 
            return res;
        Arrays.sort(nums);
        permutation(res, nums, 0);
        return res;
    }
    
    private void permutation(List<List<Integer>> res, int[] nums, int pos) {
        if (pos == nums.length) {
            List<Integer> tempList = new ArrayList<Integer>();
            for (int n : nums)
                tempList.add(n);
            res.add(tempList);
        }
        else {
            for (int i = pos; i < nums.length; i++) {
                swap(i, pos, nums);
                permutation(res, nums, pos + 1);
                swap(i, pos, nums);
            }
        }
    }
    
    private void swap(int i, int j, int[] nums) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
