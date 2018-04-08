class Solution {
    public int lengthOfLongestSubstring(String s) {
        int[] map = new int[256];
        Arrays.fill(map, -1);
        int maximum = 0;
        int start = -1;
        for (int i = 0; i < s.length(); i++)
        {
            if (map[s.charAt(i)] > start)
                start = map[s.charAt(i)];
            map[s.charAt(i)] = i;
            maximum = Math.max(maximum, i - start);
        }
        return maximum;
    }
}