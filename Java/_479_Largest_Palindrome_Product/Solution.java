class Solution {
    public int largestPalindrome(int n) {
        if (n == 1)
            return 9;
        int maxNum = (int)Math.pow(10, n) - 1;
        for (int i = maxNum; i > maxNum / 10; i--) {
            long palindrome = createPalindrome(i);
            for (long j = maxNum; j * j >= palindrome; j--)
                if (palindrome % j == 0)
                    return (int)(palindrome % 1337);
        }
        return 0;
    }
    
    public long createPalindrome(int n) {
        StringBuffer sb = new StringBuffer();
        sb.append(Integer.toString(n)).reverse();
        return Long.valueOf(n + sb.toString());
    }
}