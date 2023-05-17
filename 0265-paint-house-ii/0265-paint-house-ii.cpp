class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();
        int k = costs[0].size();
        vector<vector<int>> dp(n, vector<int>(k, 1e9));
        for (int i = 0; i < k; i++) {
            dp[0][i] = costs[0][i];
        }
        for (int x = 1; x < n; x++) {
            for (int y = 0; y < k; y++) {
                for (int z = 0; z < k; z++) {
                    if (y == z) continue;
                    dp[x][y] = min(dp[x - 1][z], dp[x][y]);   
                }
                dp[x][y] += costs[x][y];
            }
        }
        int res = 1e9;
        for (int i = 0; i < k; i++) {
            res = min(res, dp[n - 1][i]);
        }
        return res;
    }
};