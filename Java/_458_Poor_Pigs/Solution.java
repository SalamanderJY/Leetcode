class Solution {
    public int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        if (buckets <= 1)
            return 0;
        int side = minutesToTest / minutesToDie + 1;
        int pigs = 1;
        int num = side;
        while (num < buckets) {
            num = num * side;
            pigs++;
        }
        return pigs;
    }
}