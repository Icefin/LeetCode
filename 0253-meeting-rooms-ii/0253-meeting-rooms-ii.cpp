class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int res = 0;
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < intervals.size(); i++) {
            while (!pq.empty() && pq.top() <= intervals[i][0]) {
                pq.pop();
            }
            pq.push(intervals[i][1]);
            res = max(res, (int)pq.size());
        }
        return res;
    }
};