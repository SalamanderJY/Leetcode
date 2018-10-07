#include <string>
#include <stack>
#include <map>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
	stack<char> stack;
	map<char, char> map = { { ']', '[' }, { ')', '(' }, { '}', '{' } };
	for (int i = 0; i < s.length(); i++) {
	    if (s.at(i) == '(' || s.at(i) == '[' || s.at(i) == '{') {
		stack.push(s.at(i));
	    }
	    else {
		if (stack.empty())
		    return false;
		char top = stack.top();
		if (top != map[s.at(i)])
		    return false;
		stack.pop();
	    }
	}
	return stack.empty();
    }
};
