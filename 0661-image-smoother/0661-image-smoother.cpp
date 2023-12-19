class Solution {
public:
    public:
    std::vector<std::vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                res[r][c] = smoothen(img, r, c);
            }
        }

        return res;
    }

private:
    int smoothen(vector<vector<int>>& img, int r, int c) {
        int m = img.size();
        int n = img[0].size();
        int sum = 0;
        int count = 0;

        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                int nr = r + i;
                int nc = c + j;
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    sum += img[nr][nc];
                    ++count;
                }
            }
        }

        return sum / count;
    }
};