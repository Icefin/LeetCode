class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int res = 0;
        int n = isConnected.size();
        vector<vector<int>> graph(n, vector<int>());
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isConnected[i][j]) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        vector<int> isVisited(n, false);
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (isVisited[i]) {
                continue;
            }
            
            q.push(i);
            while (!q.empty()) {
                int curr = q.front(); q.pop();
                
                for (auto next : graph[curr]) {
                    if (isVisited[next]) {
                        continue;
                    }
                
                    isVisited[next] = true;
                    q.push(next);
                }
            }
            res++;
        }
        return res;
    }
};