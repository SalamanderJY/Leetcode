char* longestCommonPrefix(char** strs, int strsSize) {
    int min = 0;
    if (strsSize == 0 || strlen(strs[0]) == 0)
        return "";
    while (strsSize > 0) {
        for (int i = 0; i < strsSize; i++) {
            if (strlen(strs[i]) == min || strs[i][min] != strs[0][min]) {
                strs[0][min] = '\0';
                return strs[0];
            }
        }
        min++;
    }
    return "";
}
