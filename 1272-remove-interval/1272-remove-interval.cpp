class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        vector<vector<int>> res;
        int n = intervals.size();
        for (int i = 0; i < n; ++i) {
            if (intervals[i][1] < toBeRemoved[0]) {
                res.emplace_back(intervals[i]);
            }
            else if (intervals[i][0] < toBeRemoved[0] && intervals[i][1] <= toBeRemoved[1]) {
                res.push_back({intervals[i][0], toBeRemoved[0]});
            }
            else if (intervals[i][0] < toBeRemoved[0] && intervals[i][1] > toBeRemoved[1]) {
                res.push_back({intervals[i][0], toBeRemoved[0]});
                res.push_back({toBeRemoved[1], intervals[i][1]});
            }
            else if (intervals[i][0] >= toBeRemoved[0] && intervals[i][1] <= toBeRemoved[1]) {
                 continue;
            }
            else if (intervals[i][0] >= toBeRemoved[0] && intervals[i][0] <= toBeRemoved[1] && intervals[i][1] > toBeRemoved[1]) {
                res.push_back({toBeRemoved[1], intervals[i][1]});
            }
            else {
                res.push_back({intervals[i]});
            }
        }
        return res;
    }
};