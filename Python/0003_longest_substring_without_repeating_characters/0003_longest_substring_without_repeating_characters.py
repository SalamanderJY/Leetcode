class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        '''
        A Substring without repeating characters,
        Using two pointers,(start and i, i is current traversed char),
        No repeating char between two pointers,
        So, the max length between two pointers is the answer.
        When find the repeating char,
        the start pointer will move to the position + 1 of appeared char where found last time,
        continued traversed until i == len(s).
        '''
        mapping = [-1] * 256
        maximum = 0
        start = -1
        for i in range(len(s)):
            if mapping[ord(s[i])] > start:
                start = mapping[ord(s[i])]
            mapping[ord(s[i])] = i
            maximum = max(maximum, i - start)
        return maximum
