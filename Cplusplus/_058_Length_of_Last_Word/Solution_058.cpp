class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        int start = s.size() - 1;
        
        if (s.size() <= 0)
            return 0;      
        else 
        {
            int k, i;
            for (k = 1; k < s.size() + 1; k++) 
            {
                if (s[s.size() - k] == ' ')
                    start -= 1;
                else
                    break;
            }
                    
            if (start == -1)
                return 0;
            
            for (i = k; i < s.size() + 1; i++) 
            {
                if (s[s.size() - i] != ' ')
                    count += 1;
                else
                    break;
            }

            return count;
        }
    }
};