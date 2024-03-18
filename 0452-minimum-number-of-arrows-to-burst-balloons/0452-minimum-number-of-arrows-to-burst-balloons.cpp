class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int>& v1, vector<int>& v2){
            if (v1[0] == v2[0])
                return v1[1] < v2[1];
            return v1[0] < v2[0];
        });
        int res = 0; int rangeEnd = points[0][1];
        for (int i = 0; i < points.size();) {
            while (i < points.size() && points[i][0] <= rangeEnd){
                if (points[i][1] < rangeEnd)
                    rangeEnd = points[i][1];
                i++;
            } 

            if (i < points.size())
                rangeEnd = points[i][1];
            res++;
        }
        return res;
    }
};