/*
 * insert a word into A is equal to deleting a word from B
 * delete a word from A is equal to inserting a word from B
 * replace a word from A is equal to replacing a word from B
 * 
 * state transition equation:
 * if last word of A is equal to last word of B
 *      D[i][j] = min(D[i][j−1]+1,D[i−1][j]+1,D[i−1][j−1])
 *              = 1 + min(D[i][j−1],D[i−1][j],D[i−1][j−1]−1)
 * if last word of A is NOT equal to last word of B
 *      D[i][j] = 1 + min(D[i][j−1],D[i−1][j],D[i−1][j−1])
 */

#define MIN(x, y) ((x) > (y) ? (y) : (x))

int minDistance(char * word1, char * word2)
{
    int len1 = strlen(word1);
    int len2 = strlen(word2);

    if (len1 * len2 == 0) {
        return len1 + len2;
    }

    int **dp = malloc(sizeof(int *) * (len1 + 1));
    for (int i = 0; i < len1 + 1; i++) {
        dp[i] = malloc(sizeof(int) * (len2 + 1));
    }

    for (int i = 0; i < len1 + 1; i++) {
        dp[i][0] = i;
    }

    for (int j = 0; j < len2 + 1; j++) {
        dp[0][j] = j;
    }

    for (int i = 1; i < len1 + 1; i++) {
        for (int j = 1; j < len2 + 1; j++) {
            int ins = dp[i - 1][j] + 1;
            int del = dp[i][j - 1] + 1;
            int rep = dp[i - 1][j - 1] + 1;
            if (word1[i - 1] == word2[j - 1]) {
                rep--;
            }
            dp[i][j] = MIN(ins, MIN(del, rep));
        }
    }
    int res = dp[len1][len2];

    for (int i = 0; i < len1 + 1; i++) {
        free(dp[i]);
    }
    free(dp);

    return res;
}