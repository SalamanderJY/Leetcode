class Solution {
    public List<String> generateParentheses(int n) {
        List<String> result = new ArrayList<String>();
        addParentheses(result, "", n, 0);
        return result;
    }
    
    public void addParentheses(List<String> result, String str, int notAdd, int notMatch) {
        if (notMatch == 0 && notAdd == 0) {
            result.add(str);
            return;
        }
        if (notMatch > 0)
            addParentheses(result, str + ')', notAdd, notMatch - 1);
        if (notAdd > 0)
            addParentheses(result, str + '(', notAdd - 1, notMatch + 1);
    }  
}
