class Solution:
    def findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        if len(words) == 0:
            return []
        wordCnt = {}
        wordCntTmp = {}
        res = []
        for i in range(len(words)):
            if words[i] in wordCnt:
                wordCnt[words[i]] += 1
            else:
                wordCnt[words[i]] = 1
        for i in range(0, len(s) - len(words[0]) * len(words) + 1):
            j = 0
            wordCntTmp.clear()
            while j < len(words):
                word = s[i + j * len(words[0]) : i + j * len(words[0]) + len(words[0])]
                if word in wordCnt:
                    if word in wordCntTmp:
                        wordCntTmp[word] += 1
                    else:
                        wordCntTmp[word] = 1
                    if wordCntTmp[word] > wordCnt[word]:
                        break
                else:
                    break
                j += 1
            if j == len(words):
                res.append(i)
        return res