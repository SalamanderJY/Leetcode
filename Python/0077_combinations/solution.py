class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        def dfs(idx, cur):
            if len(cur) == k:
                res.append(cur[:])
            for i in range(idx, n + 1):
                cur.append(i)
                dfs(i + 1, cur)
                cur.pop()
        res = []
        dfs(1, [])
        return res
