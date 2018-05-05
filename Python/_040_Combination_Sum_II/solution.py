class Solution:
    def combinationSum2(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        def backtrack(candidates, target, i, current):
            if target < 0 or i > len(candidates):
                return
            if target == 0:
                res.append(current)
                return
            if i <= len(candidates) - 1:
                backtrack(candidates, target - candidates[i], i + 1, current + [candidates[i]])
                backtrack(candidates, target, i + 1, current)

        res = []
        candidates = sorted(candidates)
        backtrack(candidates, target, 0, [])
        no_duplicate_res = []
        for i in res:
            if i not in no_duplicate_res:
                no_duplicate_res.append(i)        
        return no_duplicate_res
