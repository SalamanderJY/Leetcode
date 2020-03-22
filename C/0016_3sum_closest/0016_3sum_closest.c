int cmp(const void* a, const void* b) 
{
    return *(int*)a - *(int*)b;
}


int threeSumClosest(int* nums, int numsSize, int target) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int res = nums[0] + nums[1] + nums[2];
    for (int i = 0; i < numsSize - 2; i++) {
        int left = i + 1;
        int right = numsSize - 1;
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        while (left < right) {
            int threeSum = nums[i] + nums[left] + nums[right];
            if (threeSum > target) {
                right--;
            }
            else if (threeSum < target) {
                left++;
            }
            else {
                return target;
            }
            res = abs(threeSum - target) > abs(res - target) ? res : threeSum;
        }
    }
    return res;
}