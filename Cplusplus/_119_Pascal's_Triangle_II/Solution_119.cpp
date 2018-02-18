class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> curRow;
		if (rowIndex < 0)
			return curRow;

		curRow.push_back(1);
		for (int row = 0; row < rowIndex; row++)
		{
			// push in 1 at the end of each row
			curRow.push_back(1);
			// construct each row from back to front
			for (int i = row; i >= 1; i--)
				curRow[i] = curRow[i] + curRow[i - 1];
		}
		return curRow;
    }
};