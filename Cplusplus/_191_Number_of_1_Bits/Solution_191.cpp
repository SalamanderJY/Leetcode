class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t result = 0;
        for (int i = 0; i < 32; i++, n >>= 1)
            if (n & 1 > 0)
                result++;
        return result;
    }
};