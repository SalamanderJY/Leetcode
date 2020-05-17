/* KMP find slide distance of needle */
int * findNext(char *needle)
{
    int len = strlen(needle);
    int *next = (int *)malloc(len * sizeof(int));
    for (int i = 0; i < len; i++) {
        next[i] = 0;
    }
    int i = -1;
    int j = 0;
    next[0] = -1;

    while (j < len - 1) {
        if (i == -1 || needle[i] == needle[j]) {
            i++;
            j++;
            next[j] = i;
        }
        else {
            i = next[i];
        }
    }
	return next;
}

int strStr(char *haystack, char *needle)
{
    int hlen = strlen(haystack);
    int nlen = strlen(needle);
    if (nlen == 0) {
        return 0;
    }
    int *next = findNext(needle);
    int i = 0;
    int j = 0;
    while (i < hlen && j < nlen) {
        if (j == -1 || haystack[i] == needle[j]) {
            i++;
            j++;
        }
        else {
            j = next[j];
        }
    }
    if (j == nlen) {
        free(next);
        return i - j;
    }
    free(next);
    return -1;
}
