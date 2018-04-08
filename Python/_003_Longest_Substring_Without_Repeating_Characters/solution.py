class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        mapping = [-1] * 256
        maximum = 0
        start = -1
        for i in range(len(s)):
            if mapping[ord(s[i])] > start:
                start = mapping[ord(s[i])]
            mapping[ord(s[i])] = i
            maximum = max(maximum, i - start)
        return maximum
