package _139_Word_Break;

import java.util.HashSet;
import java.util.Set;

public class Solution {
	
	public static void main(String[] args) {
		String s = "leetcode";
		Set<String> wordDict = new HashSet<String>();
		wordDict.add("leet");
		wordDict.add("code");
		
		Solution solution = new Solution();
		boolean result = solution.wordBreak(s, wordDict);
		System.out.println(result);
	}
	
	public boolean wordBreak(String s, Set<String> wordDict) {
        boolean[] dp = new boolean[s.length() + 1];
        dp[0] = true;
        
        for (int i = 1; i < s.length() + 1; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && wordDict.contains(s.substring(j, i))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.length()];
    }
}
