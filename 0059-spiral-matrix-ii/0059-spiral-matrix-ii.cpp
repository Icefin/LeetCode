class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res = vector<vector<int>>(n, vector<int>(n, 0));
        int r = 0, c = 0;
        int dir = 0;
        for (int i = 1; i <= n * n; i++) {
            res[r][c] = i;
            if (isValidRange(r, c, dir, n, res) == false) {
                dir = (dir + 1) % 4;
            }
            r += dr[dir];
            c += dc[dir];
        }
        return res;
    }
private :
    int dr[4] = {0, 1, 0, -1};
    int dc[4] = {1, 0, -1, 0};
    
    bool isValidRange(int r, int c, int dir, int n, vector<vector<int>>& v) {
        int nr = r + dr[dir];
        int nc = c + dc[dir];
        if (nr < 0 || nc < 0 || nr >= n || nc >= n || v[nr][nc] != 0) {
            return false;
        }
        return true;
    }
};