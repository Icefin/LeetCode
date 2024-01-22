class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> pq(sticks.begin(), sticks.end());
        
        int res = 0;
        while (pq.size() >= 2) {
            int x = pq.top(); pq.pop();
            int y = pq.top(); pq.pop();
            res += x + y;
            pq.push(x + y);
        }
        return res;
    }
};