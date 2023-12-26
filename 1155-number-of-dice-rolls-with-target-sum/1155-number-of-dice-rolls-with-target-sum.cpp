class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        constexpr int mod = (1e9 + 7);
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        
        dp[n][target] = 1;
        
        for (int u = n - 1; u >= 0; --u) {
            for (int v = 0; v <= target; ++v) {
                for (int w = 1; w <= min(k, target - v); ++w) {
                    dp[u][v] = (dp[u][v] + dp[u + 1][v + w]) % mod;
                }
            }
        }
        
        return dp[0][0];
    }
};