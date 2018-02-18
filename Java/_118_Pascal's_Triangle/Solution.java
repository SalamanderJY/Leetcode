class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        if(numRows == 0)
            return result;
        else
        {
            List<Integer> firstLayer = new ArrayList<Integer>();
            firstLayer.add(1);
            result.add(firstLayer);
            for(int i = 0; i < numRows - 1; i++)
            {
                firstLayer = singleLayer(firstLayer);
                result.add(firstLayer);
            }
            return result;
        }
    }
    
    public List<Integer> singleLayer(List<Integer> preLayer) {
        List<Integer> nextLayer = new ArrayList<Integer>();
        nextLayer.add(1);
        for(int i = 0; i < preLayer.size() - 1; i++)
            nextLayer.add(preLayer.get(i) + preLayer.get(i + 1));
        nextLayer.add(1);
        return nextLayer;
    }
}