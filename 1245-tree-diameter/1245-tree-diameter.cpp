class Solution {
public:
    int treeDiameter(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> graph(n + 1);
        for (vector<int> edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        vector<bool> isVisited(n + 1, false);
        queue<int> q;
        q.push(0); isVisited[0] = true;
        
        int maxNode;
        while (q.empty() == false) {
            int qSize = q.size();
            for (int i = 0; i < qSize; ++i) {
                int curr = q.front(); q.pop();
                for (int j = 0; j < graph[curr].size(); ++j) {
                    int next = graph[curr][j];
                    if (isVisited[next] == false) {
                        q.push(next);
                        isVisited[next] = true;
                        maxNode = next;
                    }
                }
            }
        }
        
        fill(isVisited.begin(), isVisited.end(), false);
        q.push(maxNode); isVisited[maxNode] = true;
        int diameter = 0;
        while (q.empty() == false) {
            int qSize = q.size();
            for (int i = 0; i < qSize; ++i) {
                int curr = q.front(); q.pop();
                for (int j = 0; j < graph[curr].size(); ++j) {
                    int next = graph[curr][j];
                    if (isVisited[next] == false) {
                        q.push(next);
                        isVisited[next] = true;
                        maxNode = next;
                    }
                }
            }
            diameter++;
        }
        return diameter - 1;
    }
};