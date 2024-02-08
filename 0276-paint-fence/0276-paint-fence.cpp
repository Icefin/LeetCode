class Solution {
public:
    int numWays(int n, int k) {
        vector<vector<int>> dp(2, vector<int>(n + 1, 0));
        dp[0][1] = k;   //not same as prev
        dp[1][1] = 0;   //same as prev
        
        for (int i = 2; i <= n; ++i) {
            dp[0][i] = dp[0][i - 1] * (k - 1) + dp[1][i - 1] * (k - 1);
            dp[1][i] = dp[0][i - 1];
        }
        
        return dp[0][n] + dp[1][n];
    }
};