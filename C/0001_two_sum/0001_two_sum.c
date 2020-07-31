int cmp(const void* a,const void* b)
{
    return *(int *)a - *(int *)b;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // need to be set to 2
    *returnSize = 2;
    int *res = (int *)malloc(sizeof(int) * 2);
    // sort the array
    int temp[numsSize];
    memcpy(temp, nums, sizeof(temp));
    qsort(temp, numsSize, sizeof(int), cmp);

    int i = 0;
    int j = numsSize - 1;
    int a;
    int b;
    // traverse target
    while (i < j) {   
        if ((temp[i] + temp[j]) == target) {
            a = temp[i];
            b = temp[j];
            break;
        }
        // right offset or left offset
        if (temp[i] + temp[j - 1] >= target)
            j--;
        else 
            i++;
    }
    // record result
    for (i = 0; i < numsSize; i++) {
        if (a == nums[i]) {
            res[0] = i;
            a = -1;
        }
        if (b == nums[i])
            res[1] = i;
    }
    return res;
}