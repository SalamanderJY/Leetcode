class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int res = 0;
        for (int i = 0; i < points.size(); i++)
        {
            unordered_map<int, int> map;
            for (int j = 0; j < points.size(); j++)
            {
                int distancex = points[i].first - points[j].first;
                int distancey = points[i].second - points[j].second;
                map[distancex * distancex + distancey * distancey]++;
            }
            for (auto it = map.begin(); it != map.end(); ++it) {
                res += it->second * (it->second - 1);
            }
        }
        return res;
    }
};
