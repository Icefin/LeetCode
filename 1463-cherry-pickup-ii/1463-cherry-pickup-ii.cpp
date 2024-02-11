class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int dp[71][71][71];
        memset(dp, -1, sizeof(dp));
        return dfs(0, 0, m - 1, n, m, dp, grid);
    }
    
private:
    int dfs(int r, int c1, int c2, int n, int m, int dp[71][71][71], vector<vector<int>>& grid) {
        if(c1 < 0 || c2 < 0 || c1 >= m || c2 >= m || c1 == c2) {
            return 0;
        }
        if(r == n - 1) {
            return  grid[r][c1] + grid[r][c2];
        }
        if(dp[r][c1][c2] != -1) {
            return dp[r][c1][c2];
        }
        int res = 0;
        for(int i = -1; i <= 1; ++i) {
            for(int j = -1; j <= 1; ++j) {
                res = max(res, grid[r][c1] + grid[r][c2] + dfs(r + 1, c1 + i, c2 + j, n, m, dp, grid));
            }
        }
        dp[r][c1][c2] = res;
        return dp[r][c1][c2];
    }
};