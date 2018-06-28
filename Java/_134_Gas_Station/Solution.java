class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int total = 0;
        int remain = 0;
        int start = 0;
        for (int i = 0; i < gas.length; i++) {
            total += gas[i] - cost[i];
            if (remain < 0) {
                remain = gas[i] - cost[i];
                start = i;
            }
            else
                remain += gas[i] - cost[i];
        }
        return total >= 0 ? start : -1;
    }
}