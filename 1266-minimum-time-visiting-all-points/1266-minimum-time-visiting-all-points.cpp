class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int res = 0;
        
        int n = points.size();
        for (int i = 0; i < n - 1; ++i) {
            vector<int>& pos1 = points[i];
            vector<int>& pos2 = points[i + 1];
            
            int dist1 = abs(pos1[0] - pos2[0]);
            int dist2 = abs(pos1[1] - pos2[1]);
            
            res += dist1 > dist2 ? dist1 : dist2;
        }
        return res;
    }
};