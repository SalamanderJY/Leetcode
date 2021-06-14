void backtracking(int* nums, int numsSize, int* returnSize, int** returnColumnSizes, 
                  int** result, int* sub, int numsIndex, int* resultIndex, int subIndex) {
    int* tempSub = (int *)malloc(sizeof(int) * subIndex);
    for (int i = 0; i < subIndex; i++)
        tempSub[i] = sub[i];
    result[*resultIndex] = tempSub;
    returnColumnSizes[0][*resultIndex] = subIndex;
    (*resultIndex)++;
    (*returnSize)++;

    for (int i = numsIndex; i < numsSize; i++) {
        if (i > 0 && nums[i] == nums[i - 1] && i != numsIndex) {
            continue;
        }
        sub[subIndex] = nums[i];
        subIndex++;
        backtracking(nums, numsSize, returnSize, returnColumnSizes, result, sub, i + 1, resultIndex, subIndex);
        subIndex--;
    }
}

int cmp(const void* a,const void* b)
{
    return *(int *)a - *(int *)b;
}

int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    qsort(nums, numsSize, sizeof(int), cmp);
    *returnSize = 1 << numsSize;
    int** result = (int**)malloc((*returnSize) * sizeof(int*));
    returnColumnSizes[0] = (int*)malloc((*returnSize) * sizeof(int));
    *returnSize = 0;
    if (numsSize == 0) {
        returnColumnSizes[0][0] = 0;
        return result;
    }
    int* sub = (int *)malloc(sizeof(int) * numsSize);  
    int* resultIndex;
    int initResultIndex = 0;
    resultIndex = &initResultIndex;
    backtracking(nums, numsSize, returnSize, returnColumnSizes, result, sub, 0, resultIndex, 0);
    return result;
}