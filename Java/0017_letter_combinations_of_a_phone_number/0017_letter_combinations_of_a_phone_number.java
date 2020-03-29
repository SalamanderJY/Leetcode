class Solution {
    public List<String> letterCombinations(String digits) {
        List<String> res = new ArrayList<String>();
        if (digits.length() == 0)
            return res;
        String[] map = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        res.add("");
        for (int i = 0; i < digits.length(); i++) {
            List<String> temp = new ArrayList<String>();
            for (String j : res) {
                for (int k = 0; k < map[digits.charAt(i) - '0'].length(); k++) {
                    temp.add(j.toString() + map[digits.charAt(i) - '0'].charAt(k));
                }
            }
            res = temp;
        }
        return res;
    }
}
