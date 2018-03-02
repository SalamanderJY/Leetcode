class MyQueue {
public:
    stack<int> input;
    stack<int> output;
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        while (!output.empty()) {
			input.push(output.top());
            output.pop();
		}
		input.push(x);
		while (!input.empty()) {
			output.push(input.top());
            input.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int temp = output.top();
        output.pop();
        return temp;  
    }
    
    /** Get the front element. */
    int peek() {
        return output.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return input.empty() && output.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */