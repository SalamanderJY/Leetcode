class Solution {
    public int numTrees(int n) {
        int[] f = new int[n + 1];
        f[0] = 1;
        f[1] = 1; 
        for (int i = 2; i < n + 1; ++i)
            for (int k = 1; k < i + 1; ++k)
                f[i] = f[i] + f[k - 1] * f[i - k];
        return f[n];
    }
}