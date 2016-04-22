package _14_Longest_Common_Prefix;

public class Solution {
	
	public static void main(String[] args) {
		String[] str = new String[]{
			"a",
			"a",
			"b"
		};
		
		Solution s = new Solution();
		String a = s.longestCommonPrefix(str);
		System.out.println(a);
	}
	
    public String longestCommonPrefix(String[] strs) {   
    	if(strs.length == 0)
    		return new String("");
    	else if(strs.length == 1)
    		return strs[0];
    	
    	else {
    		StringBuffer buffer = new StringBuffer();
    		if(strs[0].equals(""))
    			return new String("");
    		
    		else {
    			int num = 0;
    			char ch = strs[0].charAt(0);
    			
    			while(num < strs[0].length())
                {
                    for(int i = 0; i < strs.length; i++)
                    {
                        if(num < strs[i].length() && strs[i].charAt(num) == ch)
                        {
                            if(i == strs.length - 1)
                            {
                                buffer.append(ch);
                                num++;
                                if(num == strs[0].length())
                                	return buffer.toString();
                                else
                                	ch = strs[0].charAt(num);
                            }
                        }
                        else
                            return buffer.toString();
                    }
                    
    		    }
    			return buffer.toString();
    		}
    	}      
    }
}
