class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        //graph[a] = {b, true} : a->b, graph[a] = {b, false} : a<-b
        vector<vector<pair<int, bool>>> graph(n, vector<pair<int, bool>>());
        for (int i = 0; i < connections.size(); i++) {
            int from = connections[i][0];
            int to = connections[i][1];
            graph[from].push_back({to, true});
            graph[to].push_back({from, false});
        }
        
        int ans = 0;
        vector<bool> isVisited(n, false);
        queue<int> q_bfs;
        q_bfs.push(0);
        isVisited[0] = true;
        while (!q_bfs.empty()) {
            int curr = q_bfs.front(); q_bfs.pop();
            
            for (int i = 0; i < graph[curr].size(); i++) {
                pair<int, bool> next = graph[curr][i];
                if (isVisited[next.first])
                    continue ;
                if (next.second)
                    ans++;
                q_bfs.push(next.first);
                isVisited[next.first] = true;
            }
        }
        return (ans);
    }
};