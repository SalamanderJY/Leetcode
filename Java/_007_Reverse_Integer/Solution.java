package _7_Reverse_Integer;

public class Solution {
	
	public static void main(String[] args) {
		Solution solution = new Solution();
		int i = solution.reverse(115);
		System.out.println(i);
	}
	
    public int reverse(int x) {
    	 int rev = 0;
		 while(x!=0)
		 {
			 // judge overflow
			 if (rev != 0 && Integer.MAX_VALUE / rev < 10 && Integer.MAX_VALUE / rev > -10)
	            return 0;
			 rev = rev * 10 + x % 10;
			 x = x / 10;
		 }
		 
		 return rev;	
    }
}
