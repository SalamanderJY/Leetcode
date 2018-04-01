class Solution:
    def findRadius(self, houses, heaters):
        """
        :type houses: List[int]
        :type heaters: List[int]
        :rtype: int
        """
        houses = sorted(houses)
        heaters = sorted(heaters)
        i, radius = 0, 0
        for house in houses:
            while i < len(heaters) - 1 and house > heaters[i]:
                i += 1
            if i > 0:
                radius = max(radius, min(abs(heaters[i] - house), house - heaters[i - 1]))
            else:
                radius = max(radius, abs(house - heaters[0]))
        return radius
