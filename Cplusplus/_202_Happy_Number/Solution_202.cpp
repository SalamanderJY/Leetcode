class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, int> map;
        // if is not happy number, means existing loop in the sum except 1
        while (true) {
            int sum = 0;
            while(n) {
                sum += (n % 10) * (n % 10);
                n /= 10;
            }
            
            n = sum;
            if (map[sum] > 0)
                break;
            else
                map[sum]++;
        }
        return (n == 1);
    }
};