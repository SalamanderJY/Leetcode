/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void* a,const void* b)
{
    return *(int *)a - *(int *)b;
}


void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


int findDuplicate(int *nums, int numsSize, int value) 
{
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == value) {
            return 1;
        }
    } 
    return 0;
}


void dfs(int **res, int *nums, int numsSize, int* returnSize, int pos) 
{
    if (pos == numsSize) {
        res[*returnSize] = malloc(numsSize * sizeof(int));
        memcpy(res[(*returnSize)++], nums, numsSize * sizeof(int));
        return ;
    }
    else {
        int visit[numsSize + 1];
        int visitSize = 0;
        for (int i = pos; i < numsSize; i++) {
            if (!findDuplicate(visit, visitSize, nums[i])) {
                visit[visitSize++] = nums[i];
                swap(&nums[i], &nums[pos]);
                dfs(res, nums, numsSize, returnSize, pos + 1);
                swap(&nums[i], &nums[pos]);
            }
        }
    }
}


int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    *returnSize = 0;
    int cond = 1;
    for (int i = 1; i <= numsSize; i++) {
        cond *= i;
    }
    int **res = (int **)malloc(cond * sizeof(int *));
    if (numsSize == 0) {
        return res;
    }

    qsort(nums, numsSize, sizeof(int), cmp);
    dfs(res, nums, numsSize, returnSize, 0);

    returnColumnSizes[0] = (int *)malloc(sizeof(int) * cond);
    for (int i = 0; i < cond; i++) {
        returnColumnSizes[0][i] = numsSize;
    }
    return res;
}
