class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        int n = prob.size();
        vector<vector<double>> dp(n, vector<double>(target + 1, -1));
        return dfs(prob, target, dp, 0);
    }
    
private :
        double dfs(vector<double>& prob, int target, vector<vector<double>>& dp, int index) {
        if (target < 0) {
            return 0;
        }

        if (index == prob.size()) {
            return target == 0 ? 1 : 0;
        }

        if (dp[index][target] != -1) {
            return dp[index][target];
        }

        double wCurr = dfs(prob, target - 1, dp, index + 1) * prob[index];
        double woCurr = dfs(prob, target, dp, index + 1) * (1 - prob[index]);
        dp[index][target] = wCurr + woCurr;

        return dp[index][target];
    }
};