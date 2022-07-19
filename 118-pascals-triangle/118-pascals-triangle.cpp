class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal;
        vector<int> prevRow;
        prevRow.push_back(1);
        pascal.push_back(prevRow);
        while(--numRows)
        {
            vector<int> row;
            row.push_back(1);
            for(int i = 0; i < prevRow.size()-1; i++) {
                int add = prevRow[i] + prevRow[i+1];
                row.push_back(add);
            }
            row.push_back(1);
            pascal.push_back(row);
            prevRow.clear();
            prevRow = row;
        }
        return pascal;
    }
};