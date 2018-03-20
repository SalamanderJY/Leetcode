class Solution {
    public int longestPalindrome(String s) {
        Map<Character, Integer> map = new HashMap<Character, Integer>();
		for (int i = 0; i < s.length(); i++) {
			if (map.containsKey(s.charAt(i)))
				map.put(s.charAt(i), map.get(s.charAt(i)) + 1);
			else map.put(s.charAt(i), 1);
		}
		int	res = 0;
		int single = 0;
		Iterator it = map.keySet().iterator();  
        while(it.hasNext()) {  
            char key = (char)it.next();
            if (map.get(key) % 2 == 0)
                res += map.get(key);
            else {
                res += map.get(key) - 1;
                single = 1;
            }
        }
		return res + single;
    }
}