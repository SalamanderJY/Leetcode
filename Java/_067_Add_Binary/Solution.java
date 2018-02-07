class Solution {
    public String addBinary(String a, String b) {
        StringBuilder result = new StringBuilder();
        int carry = 0;      
        int i = a.length() - 1, j = b.length() - 1;
        while (i >= 0 || j >= 0 || carry > 0){
            if (i >= 0) 
            {
                carry += (a.charAt(i) - '0');
                i -= 1;
            }
            if (j >= 0) 
            {
                carry += (b.charAt(j) - '0');
                j -= 1;
            }
            result.append(carry % 2);
            carry = carry >> 1;
        }
        return result.reverse().toString();    
    }
}