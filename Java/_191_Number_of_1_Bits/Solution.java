public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        int result = 0;
        for (int i = 0; i < 32; i++, n >>= 1)
            if ((n & 1) > 0)
                result++;
        return result;
    }
}