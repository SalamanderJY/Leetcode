class Solution {
    public int minMoves(int[] nums) {
        int minimum = Integer.MAX_VALUE;
        int res = 0;
        for (int num : nums)
            minimum = Math.min(minimum, num);
        for (int num : nums)
            res += num - minimum;
        return res;
    }
}