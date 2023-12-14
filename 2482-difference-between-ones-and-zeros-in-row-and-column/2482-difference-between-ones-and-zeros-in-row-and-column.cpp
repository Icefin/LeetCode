class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<int> onesRow(m, 0);
        vector<int> onesCol(n, 0);
        
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1) {
                    onesRow[r]++;
                    onesCol[c]++;
                }
            }
        }
        
        vector<vector<int>> res(m, vector<int>(n));
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                int zerosRow = m - onesRow[r];
                int zerosCol = n - onesCol[c];
                
                res[r][c] = onesRow[r] + onesCol[c] - zerosRow - zerosCol;
            }
        }
        return res;
    }
};