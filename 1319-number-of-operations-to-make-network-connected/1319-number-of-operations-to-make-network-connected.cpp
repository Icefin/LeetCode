class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int cable_num = connections.size();
        vector<vector<int>> graph(n, vector<int>());
        
        for (int i = 0; i < connections.size(); i++) {
            graph[connections[i][0]].push_back(connections[i][1]);
            graph[connections[i][1]].push_back(connections[i][0]);
        }
        
        int group_cnt = 0;
        vector<bool> isVisited(n, false);
        for (int i = 0; i < n; i++) {
            if (isVisited[i])
                continue;
            queue<int> q_computer;
            q_computer.push(i);
            isVisited[i] = true;
            while (!q_computer.empty()) {
                int curr = q_computer.front(); q_computer.pop();
                
                for (int j = 0; j < graph[curr].size(); j++) {
                    if (isVisited[graph[curr][j]])
                        continue ;
                    q_computer.push(graph[curr][j]);
                    isVisited[graph[curr][j]] = true;
                }
            }
            group_cnt++;
        }
        
        return cable_num >= n - 1 ? group_cnt - 1 : -1;
    }
};