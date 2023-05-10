class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int m = mat1.size();
        int k = mat1[0].size();
        int n = mat2[0].size();
        vector<vector<int>> res = vector<vector<int>>(m, vector<int>(n, 0));
        unordered_map<int, vector<pair<int, int>>> um_mat1;
        unordered_map<int, vector<pair<int, int>>> um_mat2;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < k; c++) {
                if (mat1[r][c] != 0) {
                    um_mat1[c].push_back({r, mat1[r][c]});
                }
            }
        }
        for (int r = 0; r < k; r++) {
            for (int c = 0; c < n; c++) {
                if (mat2[r][c] != 0) {
                    um_mat2[r].push_back({c, mat2[r][c]});
                }
            }
        }
        for (auto elem1 : um_mat1) {
            int key = elem1.first;
            vector<pair<int, int>> v = elem1.second;
            for (int i = 0; i < v.size(); i++) {
                int r = v[i].first;
                int val = v[i].second;
                for (auto elem2 : um_mat2[key]) {
                    int c = elem2.first;
                    int val2 = elem2.second;
                    res[r][c] += val * val2;
                }
            }
        }
        return res;
    }
};