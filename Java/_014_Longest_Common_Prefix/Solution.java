package _014_Longest_Common_Prefix;

public class Solution {
    public String longestCommonPrefix(String[] strs) {
        int min = 0;
	 while (strs.length > 0) {
	    for (String s : strs) 
		if (s.length() == min || s.charAt(min) != strs[0].charAt(min)) 
		    return strs[0].substring(0, min);
	    min++;
	 }
	 return new String("");
    }
}
