class Solution:
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        hashmap = {}
        for c in s:
            if c not in hashmap:
                hashmap[c] = 1
            else:
                hashmap[c] += 1
        res = 0
        single = 0
        for key in hashmap:
            if hashmap[key] % 2 == 0:
                res += hashmap[key]
            else:
                res += hashmap[key] - 1
                single = 1
        return res + single