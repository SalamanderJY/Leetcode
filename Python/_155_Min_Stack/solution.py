class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.stack = []
        self.minimum = math.inf

    def push(self, x):
        """
        :type x: int
        :rtype: void
        """
        if x <= self.minimum:
            self.stack.append(self.minimum)
            self.minimum = x
        self.stack.append(x)
            

    def pop(self):
        """
        :rtype: void
        """
        top = self.stack[len(self.stack) - 1]
        if top == self.minimum:
            self.minimum = self.stack[len(self.stack) - 2]
            del self.stack[len(self.stack) - 1]
        del self.stack[len(self.stack) - 1]
            
            

    def top(self):
        """
        :rtype: int
        """
        if len(self.stack) > 0:
            return self.stack[len(self.stack) - 1]
        else:
            return None

    def getMin(self):
        """
        :rtype: int
        """
        return self.minimum


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()