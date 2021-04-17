#define LEN 128

class Solution {
public:
    string minWindow(string s, string t) {
        int hash[LEN] = { 0 }; /* hashble t */ 
        int start = 0;
        int end = 0; 
        int slen = s.size();
        int tlen = t.size(); 
        int minstart = 0, minlen = INT_MAX;    

        for (int i = 0; i < tlen; i++) {
            hash[t[i]]++;   
        }

        while (end < slen) { 
            if (hash[s[end]]-- > 0) {   
                tlen--; /* tlen is represented matching the t is brilliant */
            }
            end++;  

            while (tlen == 0) { 
                if (end - start < minlen) { 
                    minstart = start;
                    minlen = end - start;     
                }

                hash[s[start]]++;
                if (hash[s[start]] > 0) {
                    tlen++;
                }
                start++;
            }
        }
        
        if (minlen != INT_MAX) { 
            return s.substr(minstart, minlen);
        }
        return ""; 
    }
};