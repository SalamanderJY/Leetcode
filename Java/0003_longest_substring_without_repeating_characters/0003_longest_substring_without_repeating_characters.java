class Solution {
    public int lengthOfLongestSubstring(String s) {
        int[] map = new int[256];
        Arrays.fill(map, -1);
        int maximum = 0;
        int start = -1;
        for (int i = 0; i < s.length(); i++) {
            if (map[s.charAt(i)] > start)
                start = map[s.charAt(i)];
            map[s.charAt(i)] = i;
            maximum = Math.max(maximum, i - start);
        }
        return maximum;
    }
}
/*
A Substring without repeating characters,
Using two pointers,(start and i, i is current traversed char),
No repeating char between two pointers,
So, the max length between two pointers is the answer.
When find the repeating char,
the start pointer will move to the position + 1 of appeared char where found last time,
continued traversed until i == len(s).
*/
