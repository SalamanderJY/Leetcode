class Solution {
    public List<Integer> getRow(int rowIndex) {
        List<Integer> curRow = new ArrayList<Integer>();
        
        if (rowIndex < 0)
            return curRow;
        curRow.add(1);
        
        for (int row = 0; row < rowIndex; row++) 
        {
            // push in 1 at the end of each row
            curRow.add(1);
            // construct each row from back to front
            for (int i = row; i >= 1; i--) 
                curRow.set(i, curRow.get(i) + curRow.get(i - 1));
        }
        return curRow;
    }
}