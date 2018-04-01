class Solution {
    public int findRadius(int[] houses, int[] heaters) {
        Arrays.sort(houses);
		Arrays.sort(heaters);
		int i = 0;
		int	radius = 0;
        // int i = 0, radius = 0;
		for (int house : houses) {
			while (i < heaters.length - 1 && house > heaters[i])
				i++;
			if (i > 0)
				radius = Math.max(radius, Math.min(Math.abs(heaters[i] - house), house - heaters[i - 1]));
			else
				radius = Math.max(radius, Math.abs(house - heaters[0]));
		}
		return radius;
    }
}