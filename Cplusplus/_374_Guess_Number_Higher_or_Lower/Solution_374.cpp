// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        return binarySearch(1, n);
    }
    
    int binarySearch(int min, int max) {
        int mid = min + (max - min) / 2;
        if (guess(mid) == 0) {
            return mid;
        } else if (guess(mid) == -1) {
            return binarySearch(min, mid);
        } else {
            return binarySearch(mid + 1, max);
        }
    }
};
