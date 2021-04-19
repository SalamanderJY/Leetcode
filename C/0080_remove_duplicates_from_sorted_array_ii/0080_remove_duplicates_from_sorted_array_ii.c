int removeDuplicates(int* nums, int numsSize)
{
    if (numsSize == 0) 
        return 0;
    int i = 0;
    for (int j = 0; j < numsSize; j++) {
        if (i < 2) {
            nums[i] = nums[j];
            i++;
        }
        else if (nums[j] != nums[i - 2]) {
            nums[i] = nums[j];
            i++;
        }
    }
    return i;
}