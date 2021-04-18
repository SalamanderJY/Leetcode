int tempSize = 0;
int resSize = 0;
int *temp;
int **res;

void dfs(int cur, int n, int k)
{
    if (tempSize + (n - cur + 1) < k) {
        return ;
    }

    if (tempSize == k) {
        int *valid = (int *)malloc(sizeof(int) * k);
        for (int i = 0; i < k; i++) {
            valid[i] = temp[i];
        }
        res[resSize++] = valid;
        return;
    }

    temp[tempSize++] = cur;
    dfs(cur + 1, n, k); /* add cur into temp list */
    tempSize--;
    dfs(cur + 1, n, k); /* jump from cur to next element */
}


int** combine(int n, int k, int* returnSize, int** returnColumnSizes)
{ 
    temp = (int *)malloc(sizeof(int) * k);
    res = (int **)malloc(sizeof(int *) * 10240);
    tempSize = 0;
    resSize = 0; /* why need fuck initial ? */
    dfs(1, n, k);
    *returnSize = resSize;
    *returnColumnSizes = malloc(sizeof(int) * resSize);
    for (int i = 0; i < resSize; i++) {
        (*returnColumnSizes)[i] = k;
    }
    return res;
}