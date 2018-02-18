class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if(numRows == 0)
            return result;
        else
        {
            vector<int> firstLayer;
            firstLayer.push_back(1);
            result.push_back(firstLayer);
            for(int i = 0; i < numRows - 1; i++)
            {
                firstLayer = singleLayer(firstLayer);
                result.push_back(firstLayer);
            }
            return result;
        }
    }
    
    vector<int> singleLayer(vector<int> preLayer) {
        vector<int> nextLayer;
        nextLayer.push_back(1);
        for(int i = 0; i < preLayer.size() - 1; i++)
            nextLayer.push_back(preLayer[i] + preLayer[i + 1]);
        nextLayer.push_back(1);
        return nextLayer;
    }
};