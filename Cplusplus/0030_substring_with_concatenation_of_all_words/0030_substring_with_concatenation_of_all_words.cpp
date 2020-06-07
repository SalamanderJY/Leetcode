class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (words.empty()) {
            return vector<int>();
        }
        int wordsSize = words[0].size();
        int wordsNum = words.size();
        map<string, int> wordCnt;
        map<string, int> wordCntTmp;
        vector<int> res;
        for (int i = 0; i < wordsNum; i++) {
            wordCnt[words[i]]++;
        }
        for (int i = 0; i < s.size() - wordsNum * wordsSize + 1; i++) {
            int j = 0;
            wordCntTmp.clear();
            for (j = 0; j < wordsNum; j++) {
                string word = s.substr(i + j * wordsSize, wordsSize);
                if (wordCnt.find(word) != wordCnt.end()) {
                    wordCntTmp[word]++;
                    if (wordCntTmp[word] > wordCnt[word]) {
                        break;
                    }
                }
                else {
                    break;
                }
            }
            if (j == wordsNum) {
                res.push_back(i);
            }
        }
        return res;
    }
};
