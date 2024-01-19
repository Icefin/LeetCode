class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i)
            dp[0][i] = grid[0][i];
        
        for (int r = 1; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                int optimal = 1e9;
                for (int k = 0; k < n; ++k) {
                    if (c == k)
                        continue;
                    optimal = min(optimal, dp[r - 1][k]); 
                }
                dp[r][c] = optimal + grid[r][c];
            }
        }
        
        int res = 1e9;
        for (int i = 0; i < n; ++i) {
            res = min(res, dp[n - 1][i]);
        }
        return res;
    }
};