class Solution {
public:
    string getPermutation(int n, int k) {
        string res;
        string num = "123456789";
        vector<int> factorial(n, 1);
        for (int i = 1; i < n; ++i) 
            factorial[i] = factorial[i - 1] * i;
        k--;
        for (int i = n; i >= 1; --i) {
            int j = k / factorial[i - 1];
            k %= factorial[i - 1];
            res.push_back(num[j]);
            num.erase(j, 1);
        }
        return res;
    }
};