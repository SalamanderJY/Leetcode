class Solution:
    def numberOfBoomerangs(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        count = 0
        for i in range(len(points)):
            maps = {}
            for j in range(len(points)):
                distance = pow(points[i][0] - points[j][0], 2) + pow(points[i][1] - points[j][1], 2)
                maps[distance] = maps.get(distance, 0) + 1
            for v in maps.values():
                count += v * (v - 1)
        return count

