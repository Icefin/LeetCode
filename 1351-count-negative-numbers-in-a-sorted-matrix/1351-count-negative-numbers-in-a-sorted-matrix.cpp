class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int res = 0;
        int m = grid.size();
        int n = grid[0].size();
        int c = n - 1;
        for (int r = 0; r < m; r++) {
            while (c >= 0 && grid[r][c] < 0) {
                c--;
            }
            res += n - c - 1;
        }
        return res;
    }
};