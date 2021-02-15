int lengthOfLastWord(char *s)
{
    int count = 0;
    int len = strlen(s);
    int start = len - 1;

    if (len <= 0) {
        return 0;
    } else {
        int k;
        int i;
        for (k = 1; k < len + 1; k++) {
            if (s[len - k] == ' ') {
                start -= 1;
            } else {
                break;
            }
        }

        if (start == -1) {
            return 0;
        }

        for (i = k; i < len + 1; i++) {
            if (s[len - i] != ' ') {
                count++;
            } else {
                break;
            }
        }
        return count;
    }
}