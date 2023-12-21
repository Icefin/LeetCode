class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        
        int res = 0;
        int n = points.size();
        for (int i = 0; i < n - 1; ++i) {
            res = max(res, points[i + 1][0] - points[i][0]);
        }
        return res;
    }
};