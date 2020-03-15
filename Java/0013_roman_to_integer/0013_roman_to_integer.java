package _13_Roman_to_Integer;

import java.util.HashMap;
import java.util.Map;

public class Roman {
    public int romanToInt(String s) {
        int result = 0;
        char[] str = s.toCharArray();
        if (s.length() <= 0) {
           return result;
        }
        
        Map<Character, Integer> number = new HashMap<Character, Integer>();
        number.put('I', 1);
        number.put('V', 5);
        number.put('X', 10);
        number.put('L', 50);
        number.put('C', 100);
        number.put('D', 500);
        number.put('M', 1000);
        
        for (int i = 0; i < s.length(); i++) {
            if(i == 0)
                result += number.get(str[i]);
            if (i > 0) {
                if (number.get(str[i]) <= number.get(str[i - 1])) {
                    result += number.get(str[i]);
                }
                else {
                    result = result - 2 * number.get(str[i - 1]);
                    result += number.get(str[i]);
                }
            }
        }   
        return result;
    }
}
