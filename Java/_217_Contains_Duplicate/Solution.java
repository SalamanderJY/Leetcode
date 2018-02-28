class Solution {
    public boolean containsDuplicate(int[] nums) {
        if (nums.length == 0) 
            return false;
        HashSet<Integer> appeared = new HashSet<>();
        for(int n : nums) {
            if (!appeared.add(n)) 
                return true;
        }
        return false;
    }
}