class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.back();
        vector<int> dp(n + 1, 0);
        
        for (int i = 0; i < days.size(); i++)
            dp[days[i]] = costs[0];
        
        for (int i = 1; i <= n; i++) {
            if (dp[i] == 0) {
                dp[i] = dp[i - 1];
                continue ;
            }
            dp[i] = dp[i - 1] + costs[0];
            int offset = max(0, i - 7);
            dp[i] = min(dp[i], dp[offset] + costs[1]);
            offset = max(0, i - 30);
            dp[i] = min(dp[i], dp[offset] + costs[2]);
        }
        return dp[n];
    }
};