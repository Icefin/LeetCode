class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int res = 0;
        int n = grid.size();
        unordered_map<string, int> um;
        
        for (int r = 0; r < n; r++) {
            string key = "";
            for (int c = 0; c < n; c++) {
                key += to_string(grid[r][c]) + "#";
            }
            um[key]++;
        }
        
        for (int c = 0; c < n; c++) {
            string key = "";
            for (int r = 0; r < n; r++) {
                key += to_string(grid[r][c]) + "#";
            }
            res += um[key];
        }
        return res;
    }
};