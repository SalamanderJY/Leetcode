class Solution {
    public String intToRoman(int num) {
        int[] numbers = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        String[] chars = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        StringBuffer s = new StringBuffer("");
        for(int i = 0; num > 0; num %= numbers[i], i++)
            for(int j = 0, k = num / numbers[i]; j < k; j++)
                s.append(chars[i]);
        return s.toString();
    }
}
