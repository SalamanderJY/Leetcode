package _119_Pascals_Triangle_II;

import java.util.ArrayList;
import java.util.List;

public class Solution {

	public List<Integer> getRow(int rowIndex) {
        //第n行的第1个数为1,第二个数为1×(n-1),第三个数为1×(n-1)×（n-2）/2,第四个数为1×(n-1)×（n-2）/2×（n-3）/3…依此类推
        List<Integer> curRow = new ArrayList<Integer>();
        if (rowIndex < 0) {
            return curRow;
        }
        curRow.add(1);
        for (int row = 0; row < rowIndex; row++) {
            // push in 1 at the end of each row
            curRow.add(1);
            
            // construct each row from back to front
            for (int i = row; i >= 1; i--) {
                curRow.set(i, curRow.get(i) + curRow.get(i - 1));
            }
            // [1, 2, 1]
            // [1, 2, 3, 1]
            // [1, 3, 3, 1]
            // [1, 3, 3, 4, 1]
            // [1, 3, 6, 4, 1]
            // [1, 4, 6, 4, 1]
        }
        return curRow;
    }
    
    /*public static void main(String[] args) {
		List<Integer> list = new ArrayList<Integer>();
		list = getRow(4);
	}*/
	
}
