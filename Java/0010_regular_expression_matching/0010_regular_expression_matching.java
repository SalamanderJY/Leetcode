class Solution {
    public boolean isMatch(String s, String p) {
        if (p.length() == 0) {
            return s.length() == 0;
        }
        if (p.length() == 1)
            return (s.length() == 1 && (s.charAt(0) == p.charAt(0) || p.charAt(0) == '.'));
        if (p.charAt(1) != '*') {
            if (s.length() == 0) {
                return false;
            }
            return (s.charAt(0) == p.charAt(0) || p.charAt(0) == '.') && isMatch(s.substring(1), p.substring(1));
        }
        while (s.length() != 0 && (s.charAt(0) == p.charAt(0) || p.charAt(0) == '.')) {
            // * is 0, cut the 2 chars from p's head.    
            if (isMatch(s, p.substring(2))) 
                return true;
            // else match 1 from s, cut 1 from s's head.
            s = s.substring(1);
        }
        // cut the []* 2 chars from p's head, dfs.
        return isMatch(s, p.substring(2));
    }
}