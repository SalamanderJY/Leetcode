class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        int[] countRansom = new int[26];
        int[] countMagazine = new int[26];
        for(int i = 0; i < ransomNote.length(); ++i) ++countRansom[ransomNote.charAt(i) - 'a'];
        for(int i = 0; i < magazine.length(); ++i) ++countMagazine[magazine.charAt(i) - 'a'];
        for(int i = 0; i < 26; ++i) {
            if(countRansom[i] > countMagazine[i]) break;
            if(i == 25) return true;
        }
        return false;
    }
}