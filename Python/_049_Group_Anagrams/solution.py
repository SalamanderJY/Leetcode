import collections

class Solution:
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        groups = {}
        for s in strs:
            key = ''.join(sorted(s))
            if key in groups:
                groups[key].append(s)
            else:
                groups[key] = [s]
        return list(groups.values())
        # ans = collections.defaultdict(list)
        # for s in strs:
        #     ans[''.join(sorted(s))].append(s)
        # return ans.values()