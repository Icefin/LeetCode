class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> num(n, vector<int>(m, 1));
        vector<pair<int, pair<int, int>>> cells;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cells.push_back({grid[i][j], {i,j}});
            }
        }   
        int mod = 1e9 + 7;
        sort(cells.begin(), cells.end());
        for (auto p : cells){
            int i = p.second.first;
            int j = p.second.second;
            int val = p.first;
            int count = num[i][j];
            for (int dir = 0; dir < 4; dir++){
                int x = i + dr[dir];
                int y = j + dc[dir];
                if (x >= 0 && y >= 0 && x < n && y < m && grid[x][y] < val)
                    count = (count % mod + num[x][y] % mod) % mod;
            }
            num[i][j] = count;
        }
        long long res = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                res = (res % mod + num[i][j] % mod) % mod;
            }
        }
        return res;        
    }
    
private :
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
};