class Solution {
public:
    string licenseKeyFormatting(string S, int K) {       
        transform(S.begin(), S.end(), S.begin(), ::toupper);
        int pos = S.find("-");
        while (pos != -1) {
            S.replace(pos, 1, "");
            pos = S.find("-");
        }
        int index = S.size() % K == 0 && S.size() > 0 ? K : S.size() % K;
        string result = S.substr(0, index); 
        while (index < S.size()) {
            result += "-";
            for (int i = index; i < index + K; i++)
                result += S.at(i);
            index += K;
        }
        return result;
    }
};