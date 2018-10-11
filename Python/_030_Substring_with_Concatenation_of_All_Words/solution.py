class Solution:
    def findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        if len(words) == 0:
            return []
        word_count = {}
        word_count_temp = {}
        res = []
        for i in range(len(words)):
            if words[i] in word_count:
                word_count[words[i]] += 1
            else:
                word_count[words[i]] = 1
        for i in range(0, len(s) - len(words[0]) * len(words) + 1):
            j = 0
            word_count_temp.clear()
            while j < len(words):
                word = s[i + j * len(words[0]) : i + j * len(words[0]) + len(words[0])]
                if word in word_count:
                    if word in word_count_temp:
                        word_count_temp[word] += 1
                    else:
                        word_count_temp[word] = 1
                    if word_count_temp[word] > word_count[word]:
                        break
                else:
                    break
                j += 1
            if j == len(words):
                res.append(i)
        return res

