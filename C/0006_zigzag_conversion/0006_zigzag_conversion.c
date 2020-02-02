char* convert(char *s, int numRows)
{
    int len = strlen(s);
    if (numRows <= 1) {
        return s;
    }
    char *res = (char *)malloc(sizeof(char) * (len + 1));
    int numSize = 0;
    int n = 2 * numRows - 2;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < len; j++) {
            int k = j % n;
            if (k == i || k == n - i) {
                res[numSize++] = s[j];
            }
        }
    }
    res[numSize] = '\0';
    return res;
}