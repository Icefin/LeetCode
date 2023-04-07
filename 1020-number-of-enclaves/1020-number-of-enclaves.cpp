class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = n * m;
        for (int r = 0; r < n; r++) {
            if (grid[r][0] == 1)
                ans -= mark_grid(grid, {r, 0});
            if (grid[r][m - 1] == 1)
                ans -= mark_grid(grid, {r, m - 1});
        }
        for (int c = 0; c < m; c++) {
            if (grid[0][c] == 1)
                ans -= mark_grid(grid, {0, c});
            if (grid[n - 1][c] == 1)
                ans -= mark_grid(grid, {n - 1, c});
        }
        
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (grid[r][c] == 0) ans--;
            }
        }
        return ans;
    }
    
private :
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
    int mark_grid(vector<vector<int>>& grid, pair<int, int> pos) {
        int cnt = 1;
        queue<pair<int, int>> q_pos;
        grid[pos.first][pos.second] = 2;
        q_pos.push(pos);
        
        while (!q_pos.empty()) {
            pair<int, int> curr_pos = q_pos.front(); q_pos.pop();
            
            for (int i = 0; i < 4; i++) {
                int nr = curr_pos.first + dr[i];
                int nc = curr_pos.second + dc[i];
                
                if (nr < 0 || nc < 0 || nr >= grid.size() || nc >= grid[0].size() || grid[nr][nc] != 1)
                    continue ;
                grid[nr][nc] = 2;
                q_pos.push({nr, nc});
                cnt++;
            }
        }
        return cnt;
    }    
};