class Solution {
public:
	int findRadius(vector<int>& houses, vector<int>& heaters) {
		sort(houses.begin(), houses.end());
		sort(heaters.begin(), heaters.end());
		int i = 0;
		int	radius = 0;
        // int i = 0, radius = 0;
		for (auto house : houses) {
			while (i < heaters.size() - 1 && house > heaters[i])
				i++;
			if (i > 0)
				radius = max(radius, min(abs(heaters[i] - house), house - heaters[i - 1]));
			else
				radius = max(radius, abs(house - heaters[0]));
		}
		return radius;
	}
};