class Solution:
    def islandPerimeter(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        island = 0
        neighbor = 0
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j] == 1:
                    island += 1
                    if i < len(grid) - 1 and grid[i + 1][j] == 1:
                        neighbor += 1
                    if j < len(grid[i]) - 1 and grid[i][j + 1] == 1:
                        neighbor += 1
        return 4 * island - 2 * neighbor
