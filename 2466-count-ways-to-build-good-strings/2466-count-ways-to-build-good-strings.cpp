class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        int res = 0;
        int dp[high + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        int mod = 1e9 + 7;
        
        for (int i = 1; i <= high; i++) {
            if (i >= zero) {
                dp[i] += dp[i - zero];
            }
            if (i >= one) {
                dp[i] += dp[i - one];
            }
            dp[i] %= mod;
        }
        for (int i = low; i <= high; i++) {
            res += dp[i];
            res %= mod;
        }
        return res;
    }
};