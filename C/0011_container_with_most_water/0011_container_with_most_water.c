#define min(x,y) (((x)<(y))?(x):(y))
#define max(x,y) (((x)>(y))?(x):(y))

int maxArea(int* height, int heightSize) {
    int left = 0;
    int right = heightSize - 1;
    int maximum = 0;
    while (left < right) {
        maximum = max(maximum, min(height[left], height[right]) * (right - left));
        if (height[left] < height[right])
            left++;
        else
            right--;
    }
    return maximum;
}