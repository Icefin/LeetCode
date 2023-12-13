class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int res = 0;
        int m = mat.size();
        int n = mat[0].size();
        
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (mat[r][c] == 1 && isSpecial(mat, r, c) == true)
                    res++;
            }
        }
        return res;
    }
private :
    bool isSpecial(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        
        for (int y = 0; y < m; ++y) {
            if (y == r)
                continue;
            if (mat[y][c] == 1)
                return false;
        }
        
        for (int x = 0; x < n; ++x) {
            if (x == c)
                continue;
            if (mat[r][x] == 1)
                return false;
        }
        return true;
    }
};