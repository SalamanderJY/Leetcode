/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <math.h>

char** mallocComb(int size, int colSize)
{
    char **res = (char **)malloc(size * sizeof(char *));
    for (int i = 0; i < size; i++) {
        res[i] = (char *)malloc((colSize + 1) * sizeof(char));
        res[i][0] = '\0';
    }
    return res;
}

void freeComb(char **comb, int size) 
{
    for (int i = 0; i < size; i++) {
        free(comb[i]);
    }
    free(comb);
}


char ** letterCombinations(char * digits, int* returnSize) {
    int digitsSize = strlen(digits);
    int maxComb = (int)pow(4.0, (double)(digitsSize));
    char *map[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    char **res = mallocComb(maxComb, digitsSize + 1);
    *returnSize = 0;

    if (digitsSize == 0) {
        return res;
    }

    int currComb = 1;
    for (int i = 0; i < digitsSize; i++) {
        int newComb = 0;
        char **newRes = mallocComb(maxComb, digitsSize + 1);
        for (int j = 0; j < currComb; j++) {
            for (int k = 0; k < strlen(map[digits[i] - '0']); k++) {
                int currLen = strlen(res[j]);
                strcpy(newRes[newComb], res[j]);
                newRes[newComb][currLen] = map[digits[i] - '0'][k];
                newRes[newComb][currLen + 1] = '\0';
                newComb++;
            }
        }
        freeComb(res, maxComb);
        currComb = newComb;
        *returnSize = currComb;
        res = newRes;
    }
    return res;
}