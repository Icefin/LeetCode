class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        if (coordinates[1][0] == coordinates[0][0]) {
            for (int i = 2; i < n; i++) {
                if (coordinates[0][0] != coordinates[i][0]) {
                    return false;
                }
            }
            return true;
        }
        double tilt = (double)(coordinates[1][1] - coordinates[0][1]) / (coordinates[1][0] - coordinates[0][0]);
        for (int i = 2; i < n; i++) {
            if (coordinates[i][0] == coordinates[0][0]) {
                return false;
            }
            double temp = (double)(coordinates[i][1] - coordinates[0][1]) / (coordinates[i][0] - coordinates[0][0]);
            if (tilt != temp) {
                return false;
            }
        }
        return true;
    }
};