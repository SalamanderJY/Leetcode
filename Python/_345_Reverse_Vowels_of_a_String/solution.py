class Solution:
    def reverseVowels(self, s):
        """
        :type s: str
        :rtype: str
        """
        vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'}
        slist = list(s)
        i = 0
        j = len(slist) - 1
        while i < j:
            while i < j and slist[i] not in vowels:
                i += 1
            while j > i and slist[j] not in vowels:
                j -= 1
            slist[i], slist[j] = slist[j], slist[i] 
            i += 1
            j -= 1
        return ''.join(slist)

