class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int sum = m + n - 1;
        int mm = m - 1;
        int nn = n - 1;
        while (nn >= 0 && mm >= 0) {
            if (nums1[mm] <= nums2[nn]) {
                nums1[sum] = nums2[nn];
                sum--;
                nn--;
            } else {
                nums1[sum] = nums1[mm];
                sum--;
                mm--;
            }
        }
        while (nn >= 0) {
            nums1[sum] = nums2[nn];
            sum--;
            nn--;
        }
    }
};