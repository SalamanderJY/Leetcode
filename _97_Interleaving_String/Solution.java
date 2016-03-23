package _97_Interleaving_String;

public class Solution {
    public boolean isInterleave(String s1, String s2, String s3) {
        int len1 = s1.length();
        int len2 = s2.length();
        int len3 = s3.length();
        
        char[] str1 = s1.toCharArray();
        char[] str2 = s2.toCharArray();
        char[] str3 = s3.toCharArray();
        
        if(len1 + len2 != len3)
          return false;
        
        boolean[][] matrix = new boolean[len1+1][len2+1];
        
        for(int i = 0; i < len1+1; i++) {
            for(int j = 0; j < len2+1; j++){
                if(i == 0 && j == 0)
                  matrix[i][j] = true;
                
                else if(i == 0) {
                    matrix[i][j] = matrix[i][j-1] & (str2[j-1] == str3[j-1]);
                }
                
                else if(j == 0) {
                    matrix[i][j] = matrix[i-1][j] & (str1[i-1] == str3[i-1]);
                }
                
                else {
                    matrix[i][j] = (matrix[i-1][j] & (str1[i-1] == str3[i+j-1]))|| (matrix[i][j-1] & (str2[j-1] == str3[i+j-1]));
                }
            }
        }
        return matrix[len1][len2];
    }
}
