class Solution {
    public int divide(int dividend, int divisor) {
        int sign = (dividend > 0) ^ (divisor > 0) ? -1 : 1;
        long res = 0;
        long m = Math.abs((long)dividend);
        long n = Math.abs((long)divisor);
        while (m >= n) {
            long temp = n;
            long i = 1;
            while (temp << 1 < m) {
                temp <<= 1;
                i <<= 1;
            }
            m -= temp;
            res += i;
        }
        if (sign < 0)
            res = -res;
        return res > Integer.MAX_VALUE ? Integer.MAX_VALUE : (int)res;
    }
}
