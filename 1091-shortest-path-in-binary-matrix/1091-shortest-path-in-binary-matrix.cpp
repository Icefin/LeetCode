class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] != 0) {
            return -1;
        }
        int n = grid.size();
        queue<pair<pair<int, int>, int>> q;
        q.push({{0, 0}, 1});
        grid[0][0] = 1;
        while(!q.empty()) {
            pair<pair<int, int>, int> curr = q.front(); q.pop();
            pair<int, int> pos = curr.first;
            int dist = curr.second;
            
            if (pos.first == n - 1 && pos.second == n - 1) {
                return dist;
            }
            
            for (int i = 0; i < 8; i++) {
                int nr = pos.first + dr[i];
                int nc = pos.second + dc[i];
                
                if (isValidRange(nr, nc, n) == false || grid[nr][nc] != 0) {
                    continue;
                }
                
                q.push({{nr, nc}, dist + 1});
                grid[nr][nc] = 1;
            }
        }
        return -1;
    }
    
private :
    const int dr[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    const int dc[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    
    bool isValidRange(int r, int c, int n) {
        if (r < 0 || c < 0 || r >= n || c >= n) {
            return false;
        }
        return true;
    }
};