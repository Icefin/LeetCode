class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int>> res(m, vector<int>(n));
        
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < m; ++c) {
                res[c][r] = matrix[r][c];
            }
        }
        return (res);
    }
};