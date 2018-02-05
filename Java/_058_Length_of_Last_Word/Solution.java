class Solution {
    public int lengthOfLastWord(String s) {
        int count = 0;
        int start = s.length() - 1;
        
        if (s.length() <= 0)
            return 0;      
        else 
        {
            int k, i;
            for (k = 1; k < s.length() + 1; k++) 
            {
                if (s.charAt(s.length() - k) == ' ')
                    start -= 1;
                else
                    break;
            }
                    
            if (start == -1)
                return 0;
            
            for (i = k; i < s.length() + 1; i++) 
            {
                if (s.charAt(s.length() - i) != ' ')
                    count += 1;
                else
                    break;
            }

            return count;
        }
    }
}