#define min(x, y) (((x)<(y))?(x):(y))
#define max(x, y) (((x)>(y))?(x):(y))

int largestRectangleArea(int* heights, int heightsSize) 
{
    if (heightsSize == 0)
        return 0;
    /* use array as stack */
    int stack[heightsSize + 1];
    int top = 0;
    int result = 0;
    memset(stack, 0, sizeof(int) * (heightsSize + 1));

    int* tempHeights = (int *)malloc(sizeof(int) * (heightsSize + 1));    
    for (int i = 0; i < heightsSize; i++) {
        tempHeights[i] = heights[i];
    }
    tempHeights[heightsSize] = 0;

    for (int i = 0; i < heightsSize + 1; i++) {
        while (top > 0 && tempHeights[stack[top]] >= tempHeights[i]) {
            /* pop until tempHeights[stack[top]] < tempHeights[i] or stack is empty */
            /* this is because we can calculate the size if the next diag is small than current stack top */
            /* however we cannot calc if the next is larger than the stack top */
            int height = tempHeights[stack[top--]];
            int leftSideIndex = top > 0 ? stack[top] : -1;
            result = max(result, height * (i - leftSideIndex - 1));
        }
        /* push */
        top++;
        stack[top] = i;
    }
    return result;
}

int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize)
{
    if (matrixSize < 1) 
        return 0;
    int dp[matrixSize][matrixColSize[0]];
    for (int i = 0; i < matrixSize; i++) 
        memset(dp[i], 0, matrixColSize[0]);
    int maxArea = 0;

    for (int j = 0; j < matrixColSize[0]; j++) {
        for (int i = 0; i < matrixSize; i++) {
            if (i == 0) {
                dp[i][j] = matrix[i][j] == '1' ? 1 : 0;
            } else {
                dp[i][j] = matrix[i][j] == '1' ? dp[i - 1][j] + 1 : 0;
            }
        }
    }

    for (int i = matrixSize - 1; i >= 0; i--) {
        maxArea= max(maxArea, largestRectangleArea(dp[i], matrixColSize[0]));
    }
    
    return maxArea;
}