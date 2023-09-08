class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascalT = { { 1 } };
        for (int i = 1; i < numRows; i++) {
            vector<int> rowT = { 1 };
            for (int j = 0; j < i - 1; j++) {
                rowT.push_back(pascalT[i - 1][j] + pascalT[i - 1][j + 1]);
            }
            rowT.push_back(1);
            pascalT.push_back(rowT);
        }
        return pascalT;
    }
};