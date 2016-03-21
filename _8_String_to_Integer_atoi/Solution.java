package _8_String_to_Integer_atoi;

public class Solution {
    public int myAtoi(String str) {
        if(str.length() == 0) 
          return 0;
        
        int n = str.length();
        char[] strch = str.toCharArray();
        int result = 0;
        int index = 0;
        int flag = 1;
        
        while(strch[index] == ' ') {
        	index++;
        }
        
        if(strch[index] == '-') {
        	flag = -1;
        	index++;
        }
        
        else if(strch[index] == '+') {
        	flag = 1;
        	index++;
        }
        
        for(int i = index; i < n; i++){
            if(strch[i] < '0' || strch[i] > '9'){
                break;
            }
            //ÅÐ¶ÏÊÇ·ñÒç³ö
            if(result > Integer.MAX_VALUE / 10 || (result == Integer.MAX_VALUE / 10 && (strch[i] - '0') > Integer.MAX_VALUE % 10)){
                return flag == -1?Integer.MIN_VALUE : Integer.MAX_VALUE;
            }
            result = result * 10 + (strch[i] - '0');
        }
        
		return result * flag;
        
    }
}
