class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n);
        for (int i = 0; i < flights.size(); ++i) {
            graph[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        
        vector<int> dists(n, -1);
        queue<pair<int, int>> q; q.push({src, 0});
        while(q.empty() == false && k > -1) {
            int len = q.size();
            for(int i = 0; i < len; i++) {
                pair<int, int> cur = q.front(); q.pop();
                for(auto e: graph[cur.first]) {
                    int dist = cur.second + e.second; 
                    if(dists[e.first] == -1 || dist < dists[e.first]) {
                        dists[e.first] = dist;
                        q.push({e.first, dist});
                    }
                }
            }
            k--;
        }
        return dists[dst];
    }
};