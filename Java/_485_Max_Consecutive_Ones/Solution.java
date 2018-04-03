class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int maximum = 0;
        int temp = 0;
        for (int i : nums) 
        {
            if (i == 1)
            {
                temp++;
                maximum = Math.max(maximum, temp);
            }
            else
                temp = 0;
        }
        return maximum;
    }
}