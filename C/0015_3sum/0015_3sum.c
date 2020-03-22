const int MAX_CAPACITY = 16 * 1024;

int compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

void twoSum(int *nums, int low, int high, int target, int **results, int *returnSize)
{
    while (low < high) {
        int diff = target - nums[low];
        if (diff > nums[high]) {
            do {
                ++low;
            } while (low < high && nums[low] == nums[low - 1]);
        } 
        else if (diff < nums[high]) {
            do {
                --high;
            } while (high > low && nums[high] == nums[high + 1]);
        // target = nums[low] + nums[high]
        } else {
            results[*returnSize] = (int *)malloc(sizeof(int) * 3);
            results[*returnSize][0] = -target;
            results[*returnSize][1] = nums[low];
            results[*returnSize][2] = nums[high];
            (*returnSize)++;
            do {
                ++low;
            } while (low < high && nums[low] == nums[low - 1]);
            do {
                --high;
            } while (high > low && nums[high] == nums[high + 1]);
        }
    }
}

/**
 ** Return an array of arrays of size *returnSize.
 ** Note: The returned array must be malloced, assume caller calls free().
 **/
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    if (numsSize < 3) {
        *returnSize = 0;
        return NULL;      
    }
    // quick sort for sorting the elements
    qsort(nums, numsSize, sizeof(*nums), compare);

    *returnSize = 0;

    int i;
    int j;
    int **results = (int **)malloc(sizeof(int *) * MAX_CAPACITY);
    for (i = 0; i < numsSize; i++) {
        if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) {
            twoSum(nums, i + 1, numsSize - 1, -nums[i], results, returnSize);
        }
    }

    returnColumnSizes[0] = (int *)malloc((*returnSize) * sizeof(int));
    for (i = 0; i < (*returnSize); i++) {
        returnColumnSizes[0][i] = 3;
    }
    return results;
}
