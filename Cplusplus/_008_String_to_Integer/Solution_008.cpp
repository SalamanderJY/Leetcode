class Solution {
public:
    int myAtoi(string str) {
        if(str.size() == 0) 
            return 0;       
        int result = 0;
        int index = 0;
        int flag = 1;      
        while (str[index] == ' ')
        	index++; 
        if (str[index] == '-') {
        	flag = -1;
        	index++;
        }       
        else if (str[index] == '+') {
        	flag = 1;
        	index++;
        }       
        for(int i = index; i < str.size(); i++) {
            if (str[i] < '0' || str[i] > '9')
                break;
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && (str[i] - '0') > INT_MAX % 10))
                return flag == -1 ? INT_MIN : INT_MAX;
            result = result * 10 + (str[i] - '0');
        }     
	 return result * flag;
    }
};
