void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void nextPermutation(int* nums, int numsSize)
{
    if (numsSize == 0)
        return;
    int i, j;
    /* from the back finding the first element smaller than the next one */
    for (i = numsSize - 2; i >= 0 && nums[i+1] <= nums[i]; i--);
    if (i >= 0) {
        /* from the back finding the first element larger than nums[i] */
        for (j = numsSize - 1; j >= 0 && nums[j] <= nums[i]; j--);
        swap(&nums[i], &nums[j]);
    }
    /* reverse the part behind the nums[i], [i + 1, numsSize - 1] */
    for (j = 0; j <= (numsSize - 2 - i) / 2; j++) {
        swap(&nums[i + 1 + j], &nums[numsSize - 1 - j]);
    }
}
