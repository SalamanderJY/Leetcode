package _028_Implement_strStr;

class Solution {
    public int strStr(String haystack, String needle) {
    	if (needle.length() == 0)
	    return 0;
        int i = 0, j = 0;
	int[] next = findNext(needle);
	while (i < haystack.length() && j < needle.length()) {
	    if (j == -1 || haystack.charAt(i) == needle.charAt(j)) {
		i++;
		j++;
	    }
	    else   
		j = next[j];
	}
        if (j == needle.length())
	    return i - j;
	else
	    return -1;
    }
    
    // KMP find slide distance of needle.
    public int[] findNext(String needle) {
	int n = needle.length();
	int[] next = new int[n];
	int k = -1, j = 0;
	next[0] = -1;
	while (j < n - 1) {
	    if (k == -1 || needle.charAt(k) == needle.charAt(j)) {
		k++;
		j++;
		if (needle.charAt(k) == needle.charAt(j))           
		    next[j] = next[k];
		else
		    next[j] = k;
	    }
	    else 
		k = next[k];
	}
	return next;
    }
}
