class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> map;
		const char* arr = s.c_str();
		for (int i = 0; i < s.size(); i++) {
			if (map.find(arr[i]) != map.end())
				map[arr[i]] += 1;
			else map[arr[i]] = 1;
		}
		int	res = 0;
		int single = 0;
		for (auto it = map.begin(); it != map.end(); ++it) {
            if (it->second % 2 == 0)
                res += it->second;
            else {
                res += it->second - 1;
                single = 1;
            }
        }
		return res + single;
    }
};