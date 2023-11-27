class Solution {
public:
    int knightDialer(int n) {
        long long MOD = 1e9 + 7;
        long long dp[10][n];
        memset(dp, 0, sizeof(dp));
        
        for (int i = 0; i < 10; ++i)
            dp[i][0] = 1;
        
        for (int i = 1; i < n; ++i) {
            dp[0][i] = (dp[4][i - 1] + dp[6][i - 1]) % MOD;
            dp[1][i] = (dp[6][i - 1] + dp[8][i - 1]) % MOD;
            dp[2][i] = (dp[7][i - 1] + dp[9][i - 1]) % MOD;
            dp[3][i] = (dp[4][i - 1] + dp[8][i - 1]) % MOD;
            dp[4][i] = (dp[3][i - 1] + dp[9][i - 1] + dp[0][i - 1]) % MOD;
            dp[6][i] = (dp[1][i - 1] + dp[7][i - 1] + dp[0][i - 1]) % MOD;
            dp[7][i] = (dp[2][i - 1] + dp[6][i - 1]) % MOD;
            dp[8][i] = (dp[1][i - 1] + dp[3][i - 1]) % MOD;
            dp[9][i] = (dp[4][i - 1] + dp[2][i - 1]) % MOD;
        }
        
        int res = 0;
        for (int i = 0; i < 10; ++i)
            res = (res + dp[i][n - 1]) % MOD;
        return res;
    }
};