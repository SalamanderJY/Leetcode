class Solution:
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        if len(grid) == 0:
        	return 0
        elif len(grid[0]) == 0:
            return 0     
        for i in range(1, len(grid[0])):
        	grid[0][i] = grid[0][i - 1] + grid[0][i]       
        for i in range(1, len(grid)):
        	grid[i][0] = grid[i - 1][0] + grid[i][0]      
        for i in range(1, len(grid)):
        	for j in range(1, len(grid[i])):
        		if grid[i - 1][j] < grid[i][j - 1]:
        			grid[i][j] += grid[i - 1][j]
        		else:
        			grid[i][j] += grid[i][j - 1] 
        return grid[len(grid) - 1][len(grid[0]) - 1]

