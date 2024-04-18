class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        const int dr[4] = {-1, 0, 1, 0};
        const int dc[4] = {0, 1, 0, -1};
        int n = grid.size();
        int m = grid[0].size();
        
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < m; ++c) {
                if (grid[r][c] == 1) {
                    std::queue<std::pair<int, int>> q;
                    q.push({r, c});
                    grid[r][c] = -1;
                    int res = 0;
                    while (q.empty() == false) {
                        std::pair<int, int> pos = q.front(); q.pop();
                        
                        for (int i = 0; i < 4; ++i) {
                            int nr = pos.first + dr[i];
                            int nc = pos.second + dc[i];
                            
                            if (nr < 0 || nc < 0 || nr >= n || nc >= m || grid[nr][nc] == 0)
                                res++;
                            else if (grid[nr][nc] == -1)
                                continue;
                            else if (grid[nr][nc] == 1) {
                                q.push({nr, nc});
                                grid[nr][nc] = -1;
                            }
                                
                        }
                    }
                    return res;
                }
            }
        }
        return 0;
    }
};