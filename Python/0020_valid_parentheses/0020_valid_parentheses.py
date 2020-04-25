class Solution:
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stack = Stack()
        map = {']': '[', ')': '(', '}': '{'}
        for i in range(0, len(s)):
            if (s[i] == '(') | (s[i] == '[') | (s[i] == '{'):
                stack.push(s[i])
            else:
                if stack.isEmpty():
                    return False
                top = stack.peek()
                if top != map[s[i]]:
                    return False
                stack.pop()
        return stack.isEmpty()

    
class Stack:
    def __init__(self):
        self.items = []

    def isEmpty(self):
        return len(self.items) == 0

    def push(self, item):
        self.items.append(item)

    def pop(self):
        return self.items.pop()

    def peek(self):
        if not self.isEmpty():
            return self.items[len(self.items) - 1]

    def size(self):
        return len(self.items)
