int jump(int* nums, int numsSize)
{
    int jumpCnt = 0;
    int currPos = 0;
    while (currPos != numsSize - 1) {
        int length = nums[currPos];
        int maxPos = currPos + length;
        int movePos = 0;
        if (maxPos >= numsSize - 1) {
            jumpCnt++;
            break;
        }
        for (int i = 1; i <= length && currPos + i < numsSize; i++) {
            if (nums[currPos + i] + currPos + i > maxPos) {
                maxPos = nums[currPos + i] + currPos + i;
                movePos = i;
            }
        }
        currPos = currPos + movePos;
        jumpCnt++;
    }
    return jumpCnt;
}