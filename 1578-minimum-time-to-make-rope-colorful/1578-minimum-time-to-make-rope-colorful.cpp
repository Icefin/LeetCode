class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        priority_queue<int> pq;
        char curr = colors[0];
        pq.push(neededTime[0]);
        
        int res = 0;
        int n = colors.length();
        for (int i = 1; i < n; ++i) {
            if (colors[i] == curr) {
                pq.push(neededTime[i]);
                continue;
            }
            
            pq.pop();
            while (pq.empty() == false) {
                res += pq.top(); pq.pop();
            }
            curr = colors[i];
            pq.push(neededTime[i]);
        }
        
        pq.pop();
        while (pq.empty() == false) {
            res += pq.top(); pq.pop();
        }
        return res;
    }
};