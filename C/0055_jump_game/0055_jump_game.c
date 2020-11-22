bool canJump(int* nums, int numsSize)
{
    int maximum = nums[0];
    int index = 0;
    while (index <= maximum && index < numsSize) {
        if (index + nums[index] > maximum) {
            maximum = index + nums[index];
        }
        index++;
    }
    return maximum >= numsSize - 1 ? true : false;
}