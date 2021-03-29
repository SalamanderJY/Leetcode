char * addBinary(char * a, char * b)
{
    int len = strlen(a) > strlen(b) ? strlen(a) : strlen(b);
    char *res = (char *)malloc(sizeof(char) * (len + 2));
    res[len + 1] = '\0';
    int alen = strlen(a);
    int blen = strlen(b);
    int carry = 0;
    int i = len;
    while (alen - 1 >= 0 || blen - 1 >= 0) {
        int numa, numb;
        if (alen - 1 < 0) {
            numa = 0;
            numb = b[blen - 1] - '0';
        } else if (blen - 1 < 0) {
            numa = a[alen - 1] - '0';
            numb = 0;
        } else {
            numa = a[alen - 1] - '0';
            numb = b[blen - 1] - '0';
        }
        res[i--] = (numa + numb + carry) % 2 + '0';
        carry = (numa + numb + carry) / 2;
        alen = alen - 1 >= 0 ? alen - 1 : alen;
        blen = blen - 1 >= 0 ? blen - 1 : blen;
    }
    if (carry > 0) {
        res[0] = '1';
        return res;
    } else {
        return res + 1;
    }
}