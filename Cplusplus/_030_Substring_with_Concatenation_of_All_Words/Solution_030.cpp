class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (words.empty())
            return vector<int>();   
        int word_size = words[0].size();
        int word_nums = words.size();
        map<string, int> word_count;
        map<string, int> word_count_temp;
        vector<int> res;
        for (int i = 0; i < word_nums; i++)
            word_count[words[i]]++;
        for (int i = 0; i < s.size() - word_nums * word_size + 1; i++) {
            int j = 0;
            word_count_temp.clear();
            for (j = 0; j < word_nums; j++) {
                string word = s.substr(i + j * word_size, word_size);
                if (word_count.find(word) != word_count.end()) {
                    word_count_temp[word]++;
                    if (word_count_temp[word] > word_count[word])
                        break;
                }
                else
                    break;
            }
            if (j == word_nums)
                res.push_back(i);
        }
        return res;
    }
};
