class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int countRansom[26] = {0};
        int countMagazine[26] = {0};
        for(int i = 0; i < ransomNote.size(); ++i) ++countRansom[ransomNote[i] - 'a'];
        for(int i = 0; i < magazine.size(); ++i) ++countMagazine[magazine[i] - 'a'];
        for(int i = 0; i < 26; ++i) {
            if(countRansom[i] > countMagazine[i]) break;
            if(i == 25) return true;
        }
        return false;
    }
};