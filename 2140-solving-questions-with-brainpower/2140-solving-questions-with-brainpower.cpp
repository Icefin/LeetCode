class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        long long dp[n];
        dp[n - 1] = questions[n - 1][0];
        
        for (int i = n - 2; i >= 0; --i) {
            dp[i] = questions[i][0];
            if (i + questions[i][1] + 1 < n) {
                dp[i] += dp[i + questions[i][1] + 1];
            }
            dp[i] = max(dp[i], dp[i + 1]);
        }
        return dp[0];
    }
};