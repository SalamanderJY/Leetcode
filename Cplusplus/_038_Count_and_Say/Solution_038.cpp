class Solution {
public:
    string countAndSay(int n) {
        if (n < 1)
	    return NULL;
        string result = "1";
	 for (int i = 2; i <= n; i++)
	    result = countAndSay(result);
        return result;
    }
	
    string countAndSay(string str) {
	string result = "";
	int count = 1;
	for (int i = 1; i < str.size(); i++) {
	    if (str.at(i) == str.at(i - 1))
		count++;
	    else {
		result += to_string(count);
		result += str.at(i - 1);
		count = 1;
	    }
	}
	result += to_string(count);
	result += str.at(str.size() - 1);
	return result;
    }
};
