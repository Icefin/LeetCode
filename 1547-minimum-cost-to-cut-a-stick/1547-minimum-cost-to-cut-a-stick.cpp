class Solution {
public:
    int dp[105][105];
    int dfs(vector<int>& cuts, int i, int j) {
        // the smallest rod has length of 1
        if (j - i <= 1) return 0;
        // if the cost is calculated before, return immediately
        if (dp[i][j] != -1) return dp[i][j];
        // we initialise a large number since we are looking for the minimum number
        int ans = 1e9;
        //
        for (int k = i + 1; k < j; k++) {
            // if this rod is to be cut, the cost is the length, 
            // i.e. cuts[j] - cuts[i]
            // after the cut, it will be split into two parts
            // then we calculate the cost for left rod : dfs(cuts, i, k) 
            // and the cost for the right rod: dfs(cuts, k, j)
            ans = min(ans, cuts[j] - cuts[i] + dfs(cuts, i, k) + dfs(cuts, k, j));
        }
        return dp[i][j] = ans;
    }
    
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        memset(dp, -1, sizeof(dp));
        return dfs(cuts, 0, (int) cuts.size() - 1);
    }
};