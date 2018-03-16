class Solution {
    public int firstUniqChar(String s) {
        if (s == null || s.equals("")) return -1;
		char[] arr = s.toCharArray();
		int[] count = new int[256];				
		for (int i = 0; i < arr.length; i++) {
			count[arr[i]]++;
		}
		for (int i = 0; i < arr.length; i++) {
			if (count[arr[i]] == 1) return i; 
		}
		return -1;
    }
}