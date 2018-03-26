class Solution {
public:  
    int compress(vector<char>& chars) {
        int i = 0;
        for (int j = 0; j < chars.size();)
        {
            if (j == chars.size() - 1 || chars[j] != chars[j + 1])
                chars[i++] = chars[j++];
            else
            {
                int cur = j;
                while (j < chars.size() && chars[j] == chars[cur])
                    j++;
                chars[i++] = chars[cur];
                string num = to_string(j - cur);
                for (char c : num)
                    chars[i++] = c;
            }
        }
        return i;
    }
};