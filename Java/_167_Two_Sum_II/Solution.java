class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int start = 0;
        int end = numbers.length - 1;
        int[] result = new int[2];
        if (end < 0)
            return result;
        while (numbers[start] + numbers[end] != target && start < end) {           
            if (numbers[start] + numbers[end] < target)
                start++;
            else
                end--;
        }
        if (start > end)
            return result;
        else {
            result[0] = (start + 1);
            result[1] = (end + 1);
            return result;
        }
    }
}