class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> T = { { 'I' , 1 },
                                       { 'V' , 5 },
                                       { 'X' , 10 },
                                       { 'L' , 50 },
                                       { 'C' , 100 },
                                       { 'D' , 500 },
                                       { 'M' , 1000 } };
                                   
        int result = 0;
        
        for(int i = 0; i < s.length(); i++) 
        {
        	if(i == 0)
        		result += T[s[i]];
        	if(i > 0) {
        		if(T[s[i]] <= T[s[i-1]]) {
        			result += T[s[i]];
        		}
        		else {
        			result = result - 2 * T[s[i-1]];
        			result += T[s[i]];
        		}
        	}
        }
   
        return result;
        
    }
};
