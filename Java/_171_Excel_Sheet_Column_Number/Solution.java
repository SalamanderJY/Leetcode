class Solution {
    public int titleToNumber(String s) {
        if (s.length() == 1)
			return s.charAt(0) - 65 + 1;
		return s.charAt(s.length() - 1) - 65 + 1 + titleToNumber(s.substring(0, s.length() - 1)) * 26;
    }
}