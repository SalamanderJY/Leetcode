class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0)
	    return 0;
         int i = 0, j = 0;
	 vector<int> next = findNext(needle);
	 while (i < haystack.size() && j != needle.size()) {
	    if (j == -1 || haystack.at(i) == needle.at(j)) {
		i++;
		j++;
	    }
	    else   
		j = next[j];
	}
	if (j == needle.size())
	    return i - j;
	else
	    return -1;
    }

    // KMP find slide distance of needle.
    vector<int> findNext(string& needle) {
	int n = needle.length();
	vector<int> next(n, 0);
	int k = -1, j = 0;
	next[0] = -1;
        while (j < n - 1) {
	    if (k == -1 || needle.at(k) == needle.at(j)) {
		k++;
		j++;
		if (needle.at(k) == needle.at(j))           
		    next[j] = next[k];
		else
		    next[j] = k;
	    }
	    else 
		k = next[k];
	}
	return next;
    }
};
