class Solution {
public:
    double myPow(double x, int n) {
        long temp = n;
        if (temp == 0)
            return 1;
        else if (temp < 0)
        {
            temp = -temp;
            x = 1.0 / x;
        }
        else if (temp == 1)
            return x;
        return myPow(x * x, temp >> 1) * (n % 2 == 0 ? 1 : x);
    }
};