int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize){
    int m = obstacleGridColSize[0];
    int n = obstacleGridSize;
    long** dp = (long **)malloc(sizeof(long *) * n);
    int i , j;
    for (i = 0; i < n; i++) {
        dp[i] = (long *)malloc(sizeof(long) * m);
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            dp[i][j] = 0;
        }
    }
    for (i = 0; i < m; i++) {
        if (obstacleGrid[0][i] == 1) {
            dp[0][i] = 0;
            break;
        }
        else
            dp[0][i] = 1;
    }
    for (j = 0; j < n; j++) {
        if (obstacleGrid[j][0] == 1) {
            dp[j][0] = 0;
            break;
        }
        else
            dp[j][0] = 1;
    }
    for (i = 1; i < n; i++) {
        for (j = 1; j < m; j++) {
            if (obstacleGrid[i][j] == 0)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            else
                dp[i][j] = 0;
        }
    }
    return (int)dp[n - 1][m - 1];
}