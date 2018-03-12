class Solution {
    public String reverseVowels(String s) {
        if (s.length() < 1)
            return s;
        int start = 0;
        int end = s.length() - 1;
        char arr[] = s.toCharArray();
        while(start < end) {
            if (checkVowel(arr[start])) {
                if (checkVowel(arr[end])) {
                    char temp = arr[start];
                    arr[start] = arr[end];
                    arr[end] = temp;
                    start++;
                    end--;
                }
                else end--;
            }
            else start++;
        }
        return String.valueOf(arr);
    }
    
    public static boolean checkVowel(char c) {
        if ('a' == c || 'e' == c || 'i' == c || 'o' == c || 'u' == c
                || 'A' == c || 'E' == c || 'I' == c || 'O' == c || 'U' == c) {
            return true;
        }
        return false;
    }
}
