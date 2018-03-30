class Solution(object):
    def poorPigs(self, buckets, minutesToDie, minutesToTest):
        """
        :type buckets: int
        :type minutesToDie: int
        :type minutesToTest: int
        :rtype: int
        """
        if buckets <= 1:
            return 0
        side = minutesToTest // minutesToDie + 1
        pigs = 1
        num = side
        while num < buckets:
            num = num * side
            pigs += 1
        return pigs
