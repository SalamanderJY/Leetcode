class Solution {
    public String convert(String s, int numRows) {
        if (numRows == 1)
            return s;
        String[] result = new String[numRows];
        Arrays.fill(result, "");  
        char[] source = s.toCharArray();
        int i = 0;
        int j = 0;
        int back = numRows - 2;
        while (i < s.length()) {
            for (j = 0; j < s.length() && j < numRows && i < s.length(); j++) {
                result[j] += source[i];
                i++;
            }
            for (j = back; j < s.length() && j > 0 && i < s.length(); j--) {
                result[j] += source[i];
                i++;
            }
        }
        for (i = 0; i < numRows - 1; i++)
            result[0] += result[i + 1];
        
        return result[0];
    }
}