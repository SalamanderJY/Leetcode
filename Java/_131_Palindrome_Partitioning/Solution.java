class Solution {
    public List<List<String>> partition(String s) {
        List<String> path = new ArrayList<String>();
        List<List<String>> res = new ArrayList<List<String>>();
        backtracking(s, 0, path, res);
        return res;
    }
    
    public void backtracking(String s, int pos, List<String> path, List<List<String>> res) {
        if (pos == s.length()) {
            res.add(new ArrayList<String>(path));
            return;
        }
        for (int i = pos; i < s.length(); i++) {
            String substr = s.substring(pos, i + 1);
            if (isPalindrome(substr)) {
                path.add(substr);
                backtracking(s, i + 1, path, res);
                path.remove(path.size() - 1);
            }
        }
    }
    
    public boolean isPalindrome(String s) {
        int first = 0;
        int end = s.length() - 1;
        while (first < end)
            if (s.charAt(first++) != s.charAt(end--))
                return false;
        return true;
    }
}