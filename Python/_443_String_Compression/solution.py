class Solution:
    def compress(self, chars):
        """
        :type chars: List[str]
        :rtype: int
        """
        i, j = 0, 0
        while (j < len(chars)):
            if j == len(chars) - 1 or chars[j] != chars[j + 1]:
                chars[i] = chars[j]
                i += 1
                j += 1
            else:
                cur = j
                while j < len(chars) and chars[j] == chars[cur]:
                    j += 1
                chars[i] = chars[cur]
                i += 1
                num = str(j - cur)
                for c in num:
                    chars[i] = c
                    i += 1
        return i
