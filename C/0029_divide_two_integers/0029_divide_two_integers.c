int divide(int dividend, int divisor) 
{
    int sign = (dividend > 0) ^ (divisor > 0) ? -1 : 1;
    long long int res = 0;
    long long int m = labs((long long int)dividend);
    long long int n = labs((long long int)divisor);
    while (m >= n) {
        long long int temp = n;
        long long int i = 1;
        while (temp << 1 < m) {
            temp <<= 1;
            i <<= 1;
        }
        m -= temp;
        res += i;
    }
    if (sign < 0) {
        res = -res;
    }
    return res > INT_MAX ? INT_MAX : res;
}