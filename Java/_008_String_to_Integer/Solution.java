class Solution {
    public int myAtoi(String str) {
        if(str.length() == 0) 
          return 0;       
        int n = str.length();
        char[] array = str.toCharArray();
        int result = 0;
        int index = 0;
        int flag = 1;      
        while (array[index] == ' ')
        	index++; 
        if (array[index] == '-') {
        	flag = -1;
        	index++;
        }       
        else if (array[index] == '+') {
        	flag = 1;
        	index++;
        }       
        for(int i = index; i < n; i++) {
            if (array[i] < '0' || array[i] > '9')
                break;
            if (result > Integer.MAX_VALUE / 10 || (result == Integer.MAX_VALUE / 10 && (array[i] - '0') > Integer.MAX_VALUE % 10))
                return flag == -1 ? Integer.MIN_VALUE : Integer.MAX_VALUE;
            result = result * 10 + (array[i] - '0');
        }     
		return result * flag;
    }
}