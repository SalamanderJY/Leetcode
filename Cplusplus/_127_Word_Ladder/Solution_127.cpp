class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {             
        queue<string> visit;
        visit.push(beginWord);
        unordered_set<string> words;
        for (int i = 0; i < wordList.size(); i++)
            words.insert(wordList[i]);
        unordered_map<string, int> maps;
        maps[beginWord] = 1;
        if (words.find(beginWord) != words.end())
            words.erase(words.find(beginWord));
        while (!visit.empty()) {
            string top = visit.front();
            visit.pop();
            int level = maps[top];
            for (int i = 0; i < top.size(); i++) {
                string builder = top;
                for (char c = 'a'; c <= 'z'; c++) {
                    builder[i] = c;
                    if (builder == top)
                        continue;
                    else if (builder == endWord && words.find(builder) != words.end())
                        return level + 1;
                    else if (words.find(builder) != words.end()) {
                        visit.push(builder);
                        words.erase(words.find(builder));
                        maps[builder] = level + 1;
                    }
                }
            }
        }
        return 0;   
    }
};