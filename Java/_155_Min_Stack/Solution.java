class MinStack {

    /** initialize your data structure here. */
    public static ArrayList<Integer> stack = new ArrayList<Integer>();
    public static int minimum;
    
    public MinStack() {
        minimum = Integer.MAX_VALUE;
    }
    
    public void push(int x) {
    	if (x <= minimum) {
			stack.add(minimum);
			minimum = x;
		}
		stack.add(x);
    }
    
    public void pop() {
    	int top = stack.get(stack.size() - 1);
		stack.remove(stack.size() - 1);
		if (top == minimum) {
			minimum = stack.get(stack.size() - 1);
			stack.remove(stack.size() - 1);
		}
    }
    
    public int top() {
    	if (stack.size() > 0)
			return stack.get(stack.size() - 1);
		else
			return 0;
    }
    
    public int getMin() {
        return minimum;
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */