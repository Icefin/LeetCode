class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        for (int r = 1; r <= n; ++r) {
            for (int c = 1; c <= m; ++c) {
                dp[r][c] = dp[r - 1][c] + dp[r][c - 1] - dp[r - 1][c - 1] + matrix[r - 1][c - 1];
            }
        }
        
        int res = 0;
        for (int r = 1; r <= n; ++r) {
            for (int c = 1; c <= m; ++c) {
                for (int i = 0; i < r; ++i) {
                    for (int j = 0; j < c; ++j) {
                        int area = dp[r][c] - dp[r][j] - dp[i][c] + dp[i][j];
                        if (area == target)
                            res++;
                    }
                }
            }
        }
        return res;
    }
};