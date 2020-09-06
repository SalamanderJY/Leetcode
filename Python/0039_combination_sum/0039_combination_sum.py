class Solution:
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        def backtrack(candidates, target, i, current):
            if target < 0 or i >= len(candidates):
                return
            if target == 0:
                res.append(current)
                return
            backtrack(candidates, target - candidates[i], i, current + [candidates[i]])
            backtrack(candidates, target, i + 1, current)

        res = []
        backtrack(candidates, target, 0, [])
        return res

