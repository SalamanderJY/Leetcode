int* searchRange(int* nums, int numsSize, int target, int* returnSize)
{
    int left = 0;
    int right = numsSize - 1;
    *returnSize = 2;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            left = mid;
            right = mid;
            while (left >= 0 && nums[left] == nums[mid]) {
                left--;
            }
            while (right <= numsSize - 1 && nums[right] == nums[mid]) {
                right++;
            }
            int* found = malloc(sizeof(int) * 2);
            found[0] = left + 1;
            found[1] = right - 1;
            return found;
        }
        else if (nums[mid] < target) {
            left = mid + 1;
        }
        else if (nums[mid] > target){
            right = mid - 1;
        }
    }
    int* found = malloc(sizeof(int) * 2);
    found[0] = -1;
    found[1] = -1;
    return found;
}