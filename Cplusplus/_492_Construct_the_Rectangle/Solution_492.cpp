class Solution {
public:
    vector<int> constructRectangle(int area) {
        int w = (int)sqrt(area);
        vector<int> result;
        while (area % w != 0)
            w--;
        result.push_back((int)(area / w));
        result.push_back(w);
        return result;
    }
};