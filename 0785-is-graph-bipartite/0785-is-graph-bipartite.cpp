class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> nodeColor(n, -1);
        
        for (int i = 0; i < n; i++) {
            if (nodeColor[i] != -1)
                continue;
            queue<int> q;
            q.push(i);
            nodeColor[i] = 0;
            while (!q.empty()) {
                int currNode = q.front(); q.pop();
                int currColor = nodeColor[currNode];

                for (int i = 0; i < graph[currNode].size(); i++) {
                    int nextNode = graph[currNode][i];
                    if (nodeColor[nextNode] == -1) {
                        if (currColor == 0)
                            nodeColor[nextNode] = 1;
                        else
                            nodeColor[nextNode] = 0;
                        q.push(nextNode);
                        continue;
                    }

                    if (currColor == nodeColor[nextNode])
                        return false;
                }
            }  
        }
        return true;
    }
};