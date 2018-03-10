class NumArray {
private:
    vector<int> current_sum;
    
public:
    NumArray(vector<int> nums) {
        current_sum.push_back(0);
        for (int num : nums)
            current_sum.push_back(current_sum.back() + num);
    }
    
    int sumRange(int i, int j) {
        return current_sum[j + 1] - current_sum[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */