#define min(a, b) ((a) > (b) ? (b) : (a))

int trap(int* height, int heightSize)
{
    if (heightSize == 0) {
        return 0;
    }
    int *rightmax = malloc((heightSize + 1) * sizeof(int));
    int *leftmax = malloc((heightSize + 1) * sizeof(int));

    int tempmax = height[heightSize - 1];
    rightmax[heightSize - 1] = height[heightSize - 1];
    for (int i = heightSize - 1; i >= 0; --i) {
        if (height[i] > tempmax) {
            tempmax = height[i];
        }
        rightmax[i] = tempmax;
    }

    tempmax = height[0];
    leftmax[0] = height[0];
    for (int i = 0; i < heightSize; ++i) {
        if (height[i] > tempmax) {
            tempmax = height[i];
        }
        leftmax[i] = tempmax;
    }

    int water = 0;
    for (int i = 0; i < heightSize; ++i) {
        water += min(leftmax[i], rightmax[i]) - height[i];
    }
    free(rightmax);
    free(leftmax);
    return water;
}