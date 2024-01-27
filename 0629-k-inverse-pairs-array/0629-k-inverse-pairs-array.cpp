class Solution {
public:
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(n + 1, vector<int>(k + 1));
        
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = 1;
            for (int j = 1; j <= k; ++j) {
                for (int k = 0; k <= min(j, i - 1); ++k)
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % 1000000007;
            }
        }
        return dp[n][k];
    }
};

//1 2 3; + 4
//1 3 2; + 4
//3 1 2; + 4
//3 2 1; + 4
//2 1 3; + 4
//2 3 1; + 4