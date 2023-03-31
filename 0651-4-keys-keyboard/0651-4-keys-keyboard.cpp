class Solution {
public:
    int maxA(int n) {
        vector<int> dp(n + 1, 0);
        
        if (n <= 6)
            return (n);
        for (int i = 1; i <= 6; i++)
            dp[i] = i;
        
        for(int i = 7; i <= n; i++)
        {
            int tmp = -1;
            tmp = std::max(tmp, 1 + dp[i - 1]);
            tmp = std::max(tmp, 2 * dp[i - 3]);
            tmp = std::max(tmp, 3 * dp[i - 4]);
            tmp = std::max(tmp, 4 * dp[i - 5]);
            dp[i] = tmp;
        }

        return dp[n];
    }
};