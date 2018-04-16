class Solution {
public:
    string intToRoman(int num) {
        vector<int> numbers{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> chars{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string s = "";
        for(int i = 0; num > 0; num %= numbers[i], i++)
            for(int j = 0, k = num / numbers[i]; j < k; j++)
                s += chars[i];
        return s;
    }
};
