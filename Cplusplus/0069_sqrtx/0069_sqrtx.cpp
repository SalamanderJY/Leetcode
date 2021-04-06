class Solution {
public:
    int mySqrt(int x) {
        unsigned int result = 0;
        for (int i = 15; i >= 0; i--) {
            if ((result + (1 << i)) * (result + (1 << i)) <= x)
                result += (1 << i);
        }
        return result;
    }
};