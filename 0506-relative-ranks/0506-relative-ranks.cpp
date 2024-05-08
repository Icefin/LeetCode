class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();

        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < n; i++) {
            pq.push({score[i], i});
        }

        vector<string> rank(n);
        int place = 1;
        while (!pq.empty()) {
            int idx = pq.top().second; pq.pop();
            if (place == 1) {
                rank[idx] = "Gold Medal";
            } else if (place == 2) {
                rank[idx] = "Silver Medal";
            } else if (place == 3) {
                rank[idx] = "Bronze Medal";
            } else {
                rank[idx] = to_string(place);
            }
            place++;
        }
        return rank;
    }
};