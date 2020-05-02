void addParenthesis(char **result, char *str, int pos, int notAdd, int notMatch, int* returnSize) 
{
    if (notMatch == 0 && notAdd == 0) {
        result[(*returnSize)] = (char *)malloc(sizeof(char) * (pos + 1));
        for (int i = 0; i < pos; i++) {
            result[*returnSize][i] = str[i];
        }
        result[*returnSize][pos] = '\0';
        (*returnSize)++;
        return;
    }
    if (notMatch > 0) {
        str[pos] = ')';
        addParenthesis(result, str, pos + 1, notAdd, notMatch - 1, returnSize);
    }      
    if (notAdd > 0) {
        str[pos] = '(';
        addParenthesis(result, str, pos + 1, notAdd - 1, notMatch + 1, returnSize);
    }
    return;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** generateParenthesis(int n, int* returnSize)
{
    char **result = (char **)malloc(sizeof(char *) * 10000);  
    char str[1024];
    int pos = 0;
    (*returnSize) = 0;
    addParenthesis(result, str, 0, n, 0, returnSize);
    return result;
}