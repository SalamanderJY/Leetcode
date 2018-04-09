class Solution {
    public String longestPalindrome(String s) {
        if (s.length() == 0)
			return s;
		boolean[][] dp = new boolean[1000][1000];
		int start = 0, end = 0;
		int max = 0;
		for (int i = 0; i < s.length(); i++)
		{
			for (int j = 0; j <= i; j++)
			{
				if (s.charAt(i) == s.charAt(j) && (i - j <= 2 || dp[j + 1][i - 1]))
					dp[j][i] = true;
				if (dp[j][i] && max < i - j + 1)
				{
					max = i - j + 1;
					start = j;
				}
			}
		}
		return s.substring(start, start + max);
    }
}