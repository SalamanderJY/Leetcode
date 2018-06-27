/**
 * Definition for undirected graph.
 * class UndirectedGraphNode {
 *     int label;
 *     List<UndirectedGraphNode> neighbors;
 *     UndirectedGraphNode(int x) { label = x; neighbors = new ArrayList<UndirectedGraphNode>(); }
 * };
 */
public class Solution {
    public static Map<UndirectedGraphNode, UndirectedGraphNode> hash = new HashMap<UndirectedGraphNode, UndirectedGraphNode>();
    
    public UndirectedGraphNode cloneGraph(UndirectedGraphNode node) {
        if (node == null)
            return null;
        if (hash.containsKey(node))
            return hash.get(node);
        hash.put(node, new UndirectedGraphNode(node.label));
        for (UndirectedGraphNode val : node.neighbors) {
            UndirectedGraphNode temp = hash.get(node);
            temp.neighbors.add(cloneGraph(val));
            hash.put(node, temp);
        }
        return hash.get(node);
    }
}