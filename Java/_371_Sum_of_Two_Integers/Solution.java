class Solution {
    public int getSum(int a, int b) {
        while(a != 0)
        {
            int x = a ^ b;
            a = (a & b) << 1;
            b = x;
        }
        return b;
    }
}
