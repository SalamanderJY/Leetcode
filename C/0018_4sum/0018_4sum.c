int compare(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **fourSum(int *nums, int numsSize, int target, int *returnSize, int **returnColumnSizes) 
{
    if (nums == NULL || returnSize == NULL || numsSize < 4) {
        *returnSize = 0;
        return NULL;
    }
    int **result = NULL;
    *returnSize = 0;
    qsort(nums, numsSize, sizeof(int), compare);

    for (int i = 0; i < numsSize - 3; i++) {
        // walk through the same value
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        // if i and j are certain
        for (int j = i + 1; j < numsSize - 2; j++) {
            // walk through the same value
            if (j > i + 1 && nums[j] == nums[j - 1]) {
                continue;
            }
            int left = j + 1;
            int right = numsSize - 1;
            if (nums[i] + nums[j] + nums[right - 1] + nums[right] < target) {
                continue;
            }
            if (nums[i] + nums[j] + nums[left] + nums[left + 1] > target) {
                break;
            }
            while (left < right) {
                int sum = nums[i] + nums[j] + nums[left] + nums[right];
                if (sum == target) {
                    // same result already counted
                    if (*returnSize > 0 && 
                        (result[*returnSize - 1][0] == nums[i] && 
                         result[*returnSize - 1][1] == nums[j] && 
                         result[*returnSize - 1][2] == nums[left])) {
                        left++;
                        right--;
                        continue;
                    }
                    if ((*returnSize) % 100 == 0) {
                        result = (int **)realloc(result, sizeof(int *) * (*returnSize + 100));
                    }
                    result[*returnSize] = (int *)malloc(sizeof(int) * 4);
                    result[*returnSize][0] = nums[i];
                    result[*returnSize][1] = nums[j];
                    result[*returnSize][2] = nums[left];
                    result[*returnSize][3] = nums[right];
                    *returnSize = *returnSize + 1;
                    left++;
                    right--;
                }
                else if (sum > target) {
                    right--;
                }
                else {
                    left++;
                }
            }
        }
    }
    returnColumnSizes[0] = (int *)malloc((*returnSize) * sizeof(int));
    for (int i = 0; i < (*returnSize); i++) {
        returnColumnSizes[0][i] = 4;
    }
    return result;
}
