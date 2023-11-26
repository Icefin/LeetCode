class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int res = 0;
        for (int r = 0; r < m; ++r) { 
            for (int c = 0; c < n; ++c) {
                if (matrix[r][c] == 0 || r == 0)
                    continue;
                matrix[r][c] += matrix[r - 1][c];
            }
            
            vector<int> row = matrix[r];
            sort(row.begin(), row.end(), greater<int>());
            for (int c = 0; c < n; ++c)
                res = max(res, row[c] * (c + 1));
        }
        
        return res;
    }
};