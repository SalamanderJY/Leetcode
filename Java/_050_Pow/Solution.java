class Solution {
    public double myPow(double x, int n) {
        if (n == 0)
            return 1;
        else if (n < 0) 
            if (n == Integer.MIN_VALUE) {
                n = Integer.MAX_VALUE;
                if (x < 0)
                    x = -x;
            }
            else
                n = -n;
            x = 1 / x;
        }
        return myPow(x * x, n >> 1) * (n % 2 == 0 ? 1 : x);
    }
}