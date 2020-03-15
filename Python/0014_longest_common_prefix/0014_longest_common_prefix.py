class Solution:
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if not strs:
            return ''

        first = min(strs)
        for i in range(len(first)):
            for s in strs:
                if s[i] != first[i]:
                    return first[:i] if i > 0 else ''
        return first
