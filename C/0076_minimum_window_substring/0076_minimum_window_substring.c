#define LEN 128

char* minWindow(char *s, char *t)
{
    int hash[LEN] = {0}; /* hashble t */ 
    int start = 0;
    int end = 0; 
    int slen = strlen(s);
    int tlen = strlen(t); 
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
        char* res = (char *)malloc(sizeof(char) * (minlen + 1));
        *res = '\0';
        strncat(res, s + minstart, minlen);
        return res;
    }
    return ""; 
}