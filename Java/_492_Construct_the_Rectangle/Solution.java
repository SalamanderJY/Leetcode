class Solution {
    public int[] constructRectangle(int area) {
        int w = (int)Math.sqrt(area);
        int[] result = new int[2];
        while (area % w != 0)
            w--;
        result[0] = (int)(area / w);
        result[1] = w;
        return result;
    }
}