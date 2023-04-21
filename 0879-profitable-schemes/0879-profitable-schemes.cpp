class Solution {
public:      
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(dp, -1, sizeof(dp));
        return getProfitableScheme(0, 0, 0, n, minProfit, group, profit);
    }
    
private :
    int MOD = 1e9 + 7;
    int dp[101][101][101];
    
    int getProfitableScheme(int idx, int count, int profit, int n, int minProfit, vector<int>& group, vector<int>& profits) {
        if (idx == group.size()) {
            return (profit >= minProfit);
        }
        if (dp[idx][count][profit] != -1) {
            return dp[idx][count][profit];
        }

        int totalWays = getProfitableScheme(idx + 1, count, profit, n, minProfit, group, profits);
        if (count + group[idx] <= n) {
            totalWays += getProfitableScheme(idx + 1, count + group[idx], min(minProfit, profit + profits[idx]), n, minProfit, group, profits);
        }
        dp[idx][count][profit] = totalWays % MOD;
        return dp[idx][count][profit];
    }
};