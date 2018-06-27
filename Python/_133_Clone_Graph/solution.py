# Definition for a undirected graph node
# class UndirectedGraphNode:
#     def __init__(self, x):
#         self.label = x
#         self.neighbors = []

class Solution:
    # @param node, a undirected graph node
    # @return a undirected graph node
    def __init__(self):
        self.map = {}
    
    def cloneGraph(self, node):
        if node == None:
            return None
        if self.map.has_key(node):
            return self.map[node]
        self.map[node] = UndirectedGraphNode(node.label)
        for val in node.neighbors:
            self.map[node].neighbors.append(self.cloneGraph(val))
        return self.map[node]
