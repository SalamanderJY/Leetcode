class Solution {
    public String licenseKeyFormatting(String S, int K) {
        S = S.toUpperCase().replace("-", "");
        int index = S.length() % K == 0 && S.length() > 0? K : S.length() % K;
        StringBuffer result = new StringBuffer(S.substring(0, index)); 
        while (index < S.length()) {
            result.append('-');
            for (int i = index; i < index + K; i++)
                result.append(S.charAt(i));
            index += K;
        }
        return result.toString();
    }
}
