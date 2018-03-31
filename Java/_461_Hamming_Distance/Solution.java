class Solution {
    public int hammingDistance(int x, int y) {
        int diff = x ^ y;
        int sum = 0;
        while(diff > 0) {
            sum += diff & 1;
            diff >>= 1;
        }
        return sum;
    }
}