class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1.size() == 0 || num2.size() == 0 || num1 == "0" || num2 == "0")
            return to_string(0);
        int *res = new int[num1.size() + num2.size()];
        int length = num1.size() + num2.size();
        for (int i = 0; i < length; i++)
            res[i] = 0;
        for (int i = num1.size() - 1; i >= 0; --i) {
            if (num1.at(i) == '0') continue;    
            int carry = 0, idx = length - 1 - (num1.size() - 1 - i);  
            for (int j = num2.size() - 1; j >= 0; --j) {
                int mul = res[idx] + (num1.at(i) - '0') * (num2.at(j) - '0') + carry;
                carry = mul / 10;
                res[idx--] = mul % 10;
            }
            res[idx] += carry;
        }

        string str = "";
        for (int i = 0; i < length; ++i) {
            if (i == 0 && res[i] == 0) continue;
            str += to_string(res[i]);
        }
        delete[] res;
        return str;
    }
};
