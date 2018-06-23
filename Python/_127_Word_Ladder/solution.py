class Solution:
    def ladderLength(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: List[str]
        :rtype: int
        """
        queue = [(beginWord, 1)]
        words = set(wordList)
        visited = set()   
        while queue:
            word, dist = queue.pop(0)
            if word == endWord:
                return dist
            for i in range(len(word)):
                for j in 'abcdefghijklmnopqrstuvwxyz':
                    tmp = word[:i] + j + word[i + 1:]
                    if tmp not in visited and tmp in words:
                        queue.append((tmp, dist + 1))
                        visited.add(tmp)
        return 0