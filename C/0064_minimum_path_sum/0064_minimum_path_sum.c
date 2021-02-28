int minPathSum(int** grid, int gridSize, int* gridColSize)
{
    if (gridSize == 0)
        return 0;
    else if (gridColSize[0] == 0)
        return 0;

    for (int i = 1; i < gridColSize[0]; i++)
        grid[0][i] = grid[0][i - 1] + grid[0][i];

    for (int i = 1; i < gridSize; i++) 
        grid[i][0] = grid[i - 1][0] + grid[i][0];

    for(int i = 1; i < gridSize; i++) {
        for(int j = 1; j < gridColSize[0]; j++) {
            if(grid[i - 1][j] < grid[i][j - 1])
                grid[i][j] += grid[i - 1][j];
            else
                grid[i][j] += grid[i][j - 1];
        } 
    }
    return grid[gridSize - 1][gridColSize[0] - 1];
}