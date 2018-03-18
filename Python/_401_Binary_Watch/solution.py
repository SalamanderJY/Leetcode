class Solution:
    def readBinaryWatch(self, num):
        """
        :type num: int
        :rtype: List[str]
        """
        return ["%d:%02d" % (h, m) 
                for h in range(12) for m in range(60)
                if (bin(m) + bin(h)).count('1') == num]

