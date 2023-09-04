class Solution {
private :
    int dp[100][100];
public:
    int uniquePaths(int m, int n) {
        fill(dp[0], dp[m], 1);
        for (int r = 1; r < m; r++) {
            for (int c = 1; c < n; c++) {
                dp[r][c] = dp[r - 1][c] + dp[r][c - 1];
            }
        }
        
        return dp[m - 1][n - 1];
    }
};