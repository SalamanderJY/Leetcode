class Solution {
    public boolean isHappy(int n) {
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        // if is not happy number, means existing loop in the sum except 1
        while (true) {
            int sum = 0;
            while(n > 0) {
                sum += (n % 10) * (n % 10);
                n /= 10;
            }
            
            n = sum;
            if (map.containsKey(sum))
                break;
            else
                map.put(sum, 1);
        }
        return (n == 1);
    }
}