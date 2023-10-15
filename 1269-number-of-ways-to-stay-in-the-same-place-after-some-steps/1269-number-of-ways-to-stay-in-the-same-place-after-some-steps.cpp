class Solution {
public:
    int numWays(int steps, int arrLen) {
        arrLen = min(steps, arrLen);
        vector<vector<int>> dp(arrLen, vector(steps + 1, 0));
        dp[0][0] = 1;
        
        for (int step = 1; step <= steps; ++step) {
            for (int idx = arrLen - 1; idx >= 0; --idx) {
                int res = dp[idx][step - 1];
                if (idx > 0)
                    res = (res + dp[idx - 1][step - 1]) % (1000000007);
                if (idx < arrLen - 1)
                    res = (res + dp[idx + 1][step - 1]) % (1000000007);
                
                dp[idx][step] = res;
            }
        }
        
        return dp[0][steps];
    }
};