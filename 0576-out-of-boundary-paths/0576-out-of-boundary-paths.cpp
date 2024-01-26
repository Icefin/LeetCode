class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
        return dfs(startRow, startColumn, 0, m, n, maxMove, dp);
    }
    
private :
    const int dr[4] = {-1, 0, 1, 0};
    const int dc[4] = {0, 1, 0, -1};
    
    int dfs(int r, int c, int moveCnt, int m, int n, int maxMove, vector<vector<vector<int>>>& dp) {
        if (moveCnt > maxMove)
            return 0;
        if (isOutofBoundary(r, c, m, n) == true)
            return 1;
        
        if (dp[r][c][moveCnt] != -1)
            return dp[r][c][moveCnt];
        
        int paths = 0;
        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            paths = (paths + dfs(nr, nc, moveCnt + 1, m, n, maxMove, dp)) % 1000000007;
        }
        dp[r][c][moveCnt] = paths;
        return paths;
    }
    
    bool isOutofBoundary(int r, int c, int m, int n) {
        if (r < 0 || c < 0 || r >= m || c >= n)
            return true;
        return false;
    }
};