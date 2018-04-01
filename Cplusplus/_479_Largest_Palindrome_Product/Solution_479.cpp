class Solution {
public:
    int largestPalindrome(int n) {
        if (n == 1)
            return 9;
        int maxNum = (int)pow(10, n) - 1;
        for (int i = maxNum; i > maxNum / 10; i--) {
            long palindrome = createPalindrome(i);
            for (long j = maxNum; j * j >= palindrome; j--)
                if (palindrome % j == 0)
                    return (int)(palindrome % 1337);
        }
        return 0;
    }
    
    long createPalindrome(int n) {
        stringstream stream;
        long result;
        string palindrome = to_string(n);
        palindrome += palindrome;
        reverse(palindrome.begin() + palindrome.size() / 2, palindrome.end());
        stream << palindrome;
        stream >> result;
        return result;
    }
};