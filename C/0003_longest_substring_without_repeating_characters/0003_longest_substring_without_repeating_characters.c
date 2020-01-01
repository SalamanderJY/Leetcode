#define max(a, b) (((a) > (b)) ? (a) : (b))

int lengthOfLongestSubstring(char *s){
    int map[256];
    memset(map, -1, sizeof(map));
    int maximum = 0;
    int start = -1;
    for (int i = 0; i < strlen(s); i++) {
        if (map[s[i]] > start) {
            start = map[s[i]];
        }
        map[s[i]] = i;
        maximum = max(maximum, i - start);
    }
    return maximum;
}