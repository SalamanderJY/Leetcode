class Solution {
public:
    int firstUniqChar(string s) {
        const char* array = s.c_str();
		int count[128] = {0};
		for (int i = 0; i < s.size(); i++)
			count[array[i] - 'a']++;
		for (int i = 0; i < s.size(); i++)
			if (count[array[i] - 'a'] == 1) return i;
		return -1;
    }
};