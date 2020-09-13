/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MAX_SIZE 1024

int cmp(const void* a,const void* b)
{
    return *(int *)a - *(int *)b;
}

void dfs(int* candidates, 
        int candidatesSize, 
        int target, 
        int* returnSize, 
        int** returnColumnSizes,
        int** ans,
        int* list,
        int listSize,
        int index)
{
    if (target == 0) {
        ans[*returnSize] = (int *)malloc(listSize * sizeof(int));
        memcpy(ans[*returnSize], list, listSize * sizeof(int));
        (*returnColumnSizes)[*returnSize] = listSize;
        (*returnSize)++;
        return;
    }
    for (int i = index; i < candidatesSize; i++) {
        if (target - candidates[i] < 0) {
            break;
        }
        /* avoid the num picked repeatedly */
        if (i > index && candidates[i - 1] == candidates[i]) {
            continue;
        }
        list[listSize] = candidates[i];
        dfs(candidates, 
            candidatesSize, 
            target - candidates[i], 
            returnSize, 
            returnColumnSizes, 
            ans, 
            list,
            listSize + 1,
            i + 1);
    }
}

int** combinationSum2(int* candidates, 
                    int candidatesSize, 
                    int target, 
                    int* returnSize, 
                    int** returnColumnSizes)
{
    int** ans = (int **)malloc(sizeof(int *) * MAX_SIZE);
    int* list = (int *)malloc(sizeof(int) * target);
    qsort(candidates, candidatesSize, sizeof(int), cmp);
    *returnSize = 0;
    /* dfs and backtrack */
    dfs(candidates, 
        candidatesSize, 
        target, 
        returnSize, 
        returnColumnSizes, 
        ans, 
        list,
        0,
        0);
    free(list);
    return ans;
}
