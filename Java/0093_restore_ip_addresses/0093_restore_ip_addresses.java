class Solution {
    public List<String> restoreIpAddresses(String s) {
        List<String> res = new ArrayList<String>();
        backtracking(s, 0, "", res);
        return res;
    }
    
    public void backtracking(String s, int index, String path, List<String> res) {
        if (index == 4) {
            if (s.length() == 0)
                res.add(path.substring(0, path.length() - 1));
            return;
        }
        for (int i = 1; i < 4; ++i) {
            if (i <= s.length()) {
                if (i == 1)
                    backtracking(s.substring(i), index + 1, path + s.substring(0, i) + ".", res);
                else if (i == 2 && s.charAt(0) != '0')
                    backtracking(s.substring(i), index + 1, path + s.substring(0, i) + ".", res);
                else if (i == 3 && s.charAt(0) != '0' && Integer.parseInt(s.substring(0, 3)) < 256)
                    backtracking(s.substring(i), index + 1, path + s.substring(0, i) + ".", res);
            }
        }
    }
}
