class Solution {
    public int numberOfBoomerangs(int[][] points) {
        int res = 0;
        for (int i = 0; i < points.length; i++)
        {
            Map<Integer, Integer> map = new HashMap<Integer, Integer>();
            for (int j = 0; j < points.length; j++)
            {
                if (map.containsKey(distance(points[i], points[j]))) {
                    map.put(distance(points[i], points[j]), map.get(distance(points[i], points[j])) + 1);
                }
                else {
                    map.put(distance(points[i], points[j]), 1);
                }
            }
            // for (Map.Entry<Integer, Integer> entry : map.entrySet()) {  
            //     res += entry.getValue() * (entry.getValue() - 1);  
            // }
            for (int dis : map.values())
                res += dis * (dis - 1);
        }
        return res;
    }
    
    public int distance(int[] px, int[] py) {
        return (px[0] - py[0]) * (px[0] - py[0]) + (px[1] - py[1]) * (px[1] - py[1]);
    }
}

