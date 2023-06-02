class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> graph(n);
        for(int i = 0; i < n; i++) {
            long long r = bombs[i][2];
            long long x1 = bombs[i][0], y1 = bombs[i][1];
            for(int j = 0; j < n; j++) {
                if(i != j) {
                    long long x2 = bombs[j][0], y2 = bombs[j][1];
                    long long d = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
                    
                    if(d <= r * r) {
                        graph[i].push_back(j);
                    }
                }
            }
        }
        
        int res = 1;
        for(int i = 0; i < n; i++)
        {
            int cnt = 0;
            vector<bool> isVisited(n, false);
            dfs(graph, isVisited, cnt, i);
            res = max(res, cnt);
        }
        return res;
        
    }
    
private :
    void dfs(vector<vector<int>> &graph, vector<bool> &isVisited, int &cnt, int &i) {
        isVisited[i] = true;
        cnt++;
        for(int j = 0; j < graph[i].size(); j++)
        {
            if(!isVisited[graph[i][j]]) {
                dfs(graph, isVisited, cnt, graph[i][j]);       
            }
        }
    }
};