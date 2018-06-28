class Solution:
    def canCompleteCircuit(self, gas, cost):
        """
        :type gas: List[int]
        :type cost: List[int]
        :rtype: int
        """
        total = 0
        remain = 0
        start = 0
        for i in range(0, len(gas)):
            total += gas[i] - cost[i]
            if remain < 0:
                remain = gas[i] - cost[i]
                start = i
            else:
                remain += gas[i] - cost[i]
        return start if total >= 0 else -1
