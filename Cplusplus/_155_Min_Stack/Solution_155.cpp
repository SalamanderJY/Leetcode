class MinStack {
public:
    /** initialize your data structure here. */
	int minimum;
	vector<int> stack;

	MinStack() {
		minimum = INT_MAX;
	}

	void push(int x) {
		if (x <= minimum) {
			stack.push_back(minimum);
			minimum = x;
		}
		stack.push_back(x);
	}

	void pop() {
		int top = stack.back();
		stack.pop_back();
		if (top == minimum) {
			minimum = stack.back();
			stack.pop_back();
		}
	}

	int top() {
		if (stack.size() > 0)
			return stack.back();
		else
			return NULL;
	}

	int getMin() {
		return minimum;
	}
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */