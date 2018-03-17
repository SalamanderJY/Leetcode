class Solution {
public:
    int findNthDigit(int n) {
        int start = 1;
        int len = 1;
        int base = 9;
        while (n / len > base) {
            n = n - len * base;
            len++;
            start *= 10;
            base *= 10;
        }
        int target = start + (n - 1) / len;
        int reminder = (n - 1) % len;
        string num = to_string(target);
        return (int)num.at(reminder) - '0';
    }
};