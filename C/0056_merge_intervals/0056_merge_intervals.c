/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#define min(x, y) (((x)<(y))?(x):(y))
#define max(x, y) (((x)>(y))?(x):(y))

void sort(int** intervals, int intervalsSize) {
    for (int i = 0; i < intervalsSize; i++) {
        for (int j = i + 1; j < intervalsSize; j++) {
            if (intervals[i][0] > intervals[j][0]) {
                int start = intervals[i][0];
                int end =  intervals[i][1];
                intervals[i][0] = intervals[j][0];
                intervals[i][1] = intervals[j][1];
                intervals[j][0] = start;
                intervals[j][1] = end;
            }
        }
    }
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    if (intervalsSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    sort(intervals, intervalsSize);

    *returnSize = 0;
    int** result = (int **)malloc(sizeof(int *) * 512);        
    int start = intervals[0][0];
    int end = intervals[0][1];
    int i;
    for (i = 0; i < intervalsSize - 1; i++) {
        if (intervals[i + 1][0] <= end)
            end = max(end, intervals[i + 1][1]);
        else {
            result[*returnSize] = (int *)malloc(sizeof(int) * 2);
            result[*returnSize][0] = start;
            result[*returnSize][1] = end;
            start = intervals[i + 1][0];
            end = intervals[i + 1][1];
            (*returnSize)++;
        }
    }

    result[*returnSize] = (int *)malloc(sizeof(int) * 2);
    result[*returnSize][0] = start;
    result[*returnSize][1] = end;

    (*returnSize)++;

    returnColumnSizes[0] = (int *)malloc((*returnSize) * sizeof(int));
    for (i = 0; i < (*returnSize); i++) {
        returnColumnSizes[0][i] = 2;
    }
    return result;
}