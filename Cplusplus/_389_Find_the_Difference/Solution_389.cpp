class Solution {
public:
    char findTheDifference(string s, string t) {
        int n = t.size();
	    char c = t.at(n - 1);
	    for (int i = 0; i < n - 1; ++i) {
		    c ^= s.at(i);
		    c ^= t.at(i);
	    }
	    return c;
    }
};