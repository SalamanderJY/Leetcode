class Solution {
    public int arrangeCoins(int n) {
        return (int)(-1.0 + Math.sqrt((8L * n) + 1)) >> 1;
    }
}