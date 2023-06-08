class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int res = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] < 0) {
                    res += n - c;
                    break;
                }
            }
        }
        return res;
    }
};