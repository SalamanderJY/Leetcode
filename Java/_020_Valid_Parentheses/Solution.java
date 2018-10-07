package _020_Valid_Parentheses;

import java.util.*;

class Solution {
    public boolean isValid(String s) { 	
    	Stack<Character> stack = new Stack<Character>();
    	HashMap<Character, Character> map = new HashMap<Character, Character>();
    	map.put(']', '[');  
    	map.put('}', '{'); 
    	map.put(')', '(');  
	for (int i = 0; i < s.length(); i++) {
	    if (s.charAt(i) == '(' || s.charAt(i) == '[' || s.charAt(i) == '{') {
		stack.push(s.charAt(i));
	    }
	    else {
	        if (stack.empty())
	            return false;
		char top = stack.peek();
		if (top != map.get(s.charAt(i)))
		    return false;
		stack.pop();
	    }
	}
	return stack.empty();   
    }
}
