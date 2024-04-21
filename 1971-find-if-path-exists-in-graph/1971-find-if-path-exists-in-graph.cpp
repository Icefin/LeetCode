class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (source == destination)
            return true;
        
        vector<vector<int>> graph(n);
        for (int i = 0; i < edges.size(); ++i) {
            int from = edges[i][0];
            int to = edges[i][1];
            
            graph[from].push_back(to);
            graph[to].push_back(from);
        }
        
        vector<bool> isVisited(n, false);
        queue<int> q; q.push(source);
        isVisited[source] = true;
        
        while (q.empty() == false) {
            int curr = q.front(); q.pop();
            
            for (int i = 0; i < graph[curr].size(); ++i) {
                int next = graph[curr][i];
                
                if (next == destination)
                    return true;
                
                if (isVisited[next] == true)
                    continue;
                q.push(next);
                isVisited[next] = true;
            }
        }
        return false;
    }
};