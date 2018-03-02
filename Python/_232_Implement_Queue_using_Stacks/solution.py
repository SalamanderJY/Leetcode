class MyQueue:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.input, self.output = [], []

    def push(self, x):
        """
        :type x: int
        :rtype: nothing
        """
        self.input.append(x)

    def pop(self):
        """
        :rtype: nothing
        """
        self.move()
        temp = self.output[-1]
        self.output.pop()
        return temp

    def peek(self):
        """
        :rtype: int
        """
        self.move()
        return self.output[-1]

    def empty(self):
        """
        :rtype: bool
        """
        return (not self.input) and (not self.output) 
        
    def move(self):
        """
        :rtype nothing
        """
        if not self.output:
            while self.input:
                self.output.append(self.input.pop())
        


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()