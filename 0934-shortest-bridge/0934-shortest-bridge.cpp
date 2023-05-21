class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 1) {
                    colorGrid(r, c, grid);
                    return getDistance(grid);
                }
            }
        }
        return -1;
    }
    
private :
    int dr[4] = {0, 1, 0, -1};
    int dc[4] = {1, 0, -1, 0};
    set<pair<int, int>> startPos;
    
    bool isValidRange(int r, int c, int n) {
        if (r < 0 || c < 0 || r >= n || c >= n) {
            return false;
        }
        return true;
    }
    
    void colorGrid(int r, int c, vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        q.push({r, c});
        startPos.insert({r, c});
        grid[r][c] = 2;
        while (!q.empty()) {
            pair<int, int> pos = q.front(); q.pop();
            
            for (int i = 0; i < 4; i++) {
                int nr = pos.first + dr[i];
                int nc = pos.second + dc[i];
                
                if (isValidRange(nr, nc, n) && grid[nr][nc] != 2) {
                    if (grid[nr][nc] == 0) {
                        startPos.insert({pos.first, pos.second});
                        continue;
                    }
                    grid[nr][nc] = 2;
                    q.push({nr, nc});
                }
            }
        }
    }
    
    int getDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<pair<int, int>, int>> q;
        for (auto pos : startPos) {
            q.push({pos, 0});
        }
        
        while (!q.empty()) {
            pair<pair<int, int>, int> curr = q.front(); q.pop();
            pair<int, int> pos = curr.first;
            int dist = curr.second;
            
            for (int i = 0; i < 4; i++) {
                int nr = pos.first + dr[i];
                int nc = pos.second + dc[i];
                
                if (isValidRange(nr, nc, n) && grid[nr][nc] != 2) {
                    if (grid[nr][nc] == 1) {
                        return -dist;
                    }
                    
                    if (grid[nr][nc] == 0 || grid[nr][nc] + 1 < dist) {
                        grid[nr][nc] = dist - 1;
                        q.push({{nr, nc}, dist - 1});
                    }
                }
            }
        }
        return -1;
    }
};