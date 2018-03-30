class Solution {
    public boolean repeatedSubstringPattern(String s) {
        int i = 1;
        int j = 0;
        int[] dp = new int[s.length() + 1];
        while (i < s.length()) {
            if (s.charAt(i) == s.charAt(j)) {
                dp[++i] = ++j;
            }
            else if (j == 0)
                ++i;
            else
                j = dp[j];
        }
        return dp[s.length()] > 0 && (dp[s.length()] % (s.length() - dp[s.length()]) == 0);
    }
}