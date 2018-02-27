public class Solution {
    public boolean isIsomorphic(String s, String t) {
		
		char[] strs = s.toCharArray();
		char[] strt = t.toCharArray();
		
		Map<Character, Character> mapkey = new HashMap<Character, Character>();
		Map<Character, Character> mapvalue = new HashMap<Character, Character>();
    	boolean flag = true;
    	for(int i = 0; i < strs.length; i++) {
    		if( (!mapkey.containsKey(strs[i])) && (!mapvalue.containsKey(strt[i])) ){
    			mapkey.put(strs[i], strt[i]);
    			mapvalue.put(strt[i], strs[i]);
    		} else {
    			if(mapkey.containsKey(strs[i])){
	    			if(mapkey.get(strs[i]) == strt[i]){
	    				continue;
	    			} else {
	    				flag = false;
	    				break;
	    			}
    			} else {
    				if(mapvalue.get(strt[i]) == strs[i]){
	    				continue;
	    			} else {
	    				flag = false;
	    				break;
	    			}
    			}
    		}
    	}  	
    	return flag;   
    }
}