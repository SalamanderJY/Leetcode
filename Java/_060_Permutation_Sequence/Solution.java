class Solution {
    public String getPermutation(int n, int k) {
        StringBuilder res = new StringBuilder();
        String num = "123456789";
        int[] factorial = new int[n];
        Arrays.fill(factorial, 1);
        for (int i = 1; i < n; ++i) 
            factorial[i] = factorial[i - 1] * i;
        k--;
        for (int i = n; i >= 1; --i) {
            int j = k / factorial[i - 1];
            k %= factorial[i - 1];
            res.append(num.charAt(j));
            num = num.substring(0, j) + num.substring(j + 1);
        }
        return res.toString();
    }
}