class Solution:
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        hashmap = {'I': 1,
                   'V': 5,
                   'X': 10,
                   'L': 50,
                   'C': 100,
                   'D': 500,
                   'M': 1000}

        result = 0
        for i in range(0, len(s)):
            if i == 0:
                result += hashmap[s[i]]
            if i > 0:
                if hashmap[s[i]] <= hashmap[s[i - 1]]:
                    result += hashmap[s[i]]
                else:
                    result -= 2 * hashmap[s[i - 1]]
                    result += hashmap[s[i]]

        return result
    