class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 1)
            return matrix[0][0];

        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            dp[0][i] = matrix[0][i];
        }
        
        for (int r = 1; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (c == 0) {
                    dp[r][c] = min(dp[r - 1][c], dp[r - 1][c + 1]) + matrix[r][c];
                }
                else if (c == n - 1) {
                   dp[r][c] = min(dp[r - 1][c - 1], dp[r - 1][c]) + matrix[r][c];
                }
                else {
                    dp[r][c] = min(dp[r - 1][c - 1], min(dp[r - 1][c], dp[r - 1][c + 1])) + matrix[r][c];
                }
            }
        }
        
        int res = 1e9;
        for (int i = 0; i < n; ++i) {
            res = min(dp[n - 1][i], res);
        }
        
        return res;    
    }
};