class Solution {
public:
    int numSquares(int n) {
        std::vector<uint8_t> dp(n + 1, 255);
        dp[0] = 0;
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= 100; ++j) {
                if (i < j * j)
                    break;
                dp[i] = dp[i] < dp[i - j * j] + 1 ? dp[i] : dp[i - j * j] + 1;
            }
        }
        return dp[n];
    }
};