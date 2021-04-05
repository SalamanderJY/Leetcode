char ** fullJustify(char ** words, int wordsSize, int maxWidth, int* returnSize)
{
    int i, j, k;
    char** ans = (char **)malloc(sizeof(char *) * wordsSize);
    for (i = 0; i < wordsSize; i++) {
        ans[i] = (char *)malloc(sizeof(char) * (maxWidth + 1));
        memset(ans[i], 0, maxWidth + 1);
    }

    *returnSize = 0;
    i = 0;
    while (i < wordsSize) {
        int wordWdth = 0;
        int wordCnt = 0;

        while (i < wordsSize && wordWdth + strlen(words[i]) <= maxWidth) {
            wordWdth += strlen(words[i]) + 1;
            wordCnt++;
            i++;
        }
        int blankCnt = maxWidth - (wordWdth - wordCnt);
        int blankAvg = wordCnt == 1 ? 0 : blankCnt / (wordCnt - 1);
        int blankRemain = wordCnt == 1 ? blankCnt : blankCnt % (wordCnt - 1);

        for (j = i - wordCnt; j < i; j++) {
            /* int sprintf_s (char* strDest, size_t destMax, const char* format, ...) better */
            sprintf(ans[*returnSize] + strlen(ans[*returnSize]), "%s", words[j]);
            if (wordCnt == 1) {
                for (k = 0; k < blankCnt; k++) {
                    sprintf(ans[*returnSize] + strlen(ans[*returnSize]), "%c", ' ');
                }
            } else if (i == wordsSize) {
                if (strlen(ans[*returnSize]) < maxWidth) {
                    sprintf(ans[*returnSize] + strlen(ans[*returnSize]), "%c", ' ');
                    blankCnt--;
                    if (j == wordsSize - 1) {
                        for (k = 0; k < blankCnt; k++) {
                            sprintf(ans[*returnSize] + strlen(ans[*returnSize]), "%c", ' ');
                        }
                    }
                }
            } else {
                if (j == i - 1) {
                    break;
                }
                for (k = 0; k < blankAvg; k++) {
                    sprintf(ans[*returnSize] + strlen(ans[*returnSize]), "%c", ' ');
                }
                if (blankRemain > 0) {
                    sprintf(ans[*returnSize] + strlen(ans[*returnSize]), "%c", ' ');
                    blankRemain--;
                }
            }
        }
        (*returnSize)++;
    }
    return ans;
}