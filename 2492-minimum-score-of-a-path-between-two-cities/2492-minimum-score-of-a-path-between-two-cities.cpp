class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        int ans = INT_MAX;
        
        vector<vector<int>> graph(n + 1, vector<int>());
        vector<int> city_cost(n + 1, INT_MAX);
        for (int i = 0; i < roads.size(); i++) {
            int from = roads[i][0];
            int to = roads[i][1];
            int cost = roads[i][2];
            graph[from].push_back(to);
            graph[to].push_back(from);
            if (city_cost[from] > cost) city_cost[from] = cost;
            if (city_cost[to] > cost) city_cost[to] = cost;
        }
        
        queue<int> q_city;
        q_city.push(1);
        vector<bool> isVisited(n + 1, false);
        isVisited[1] = true;
        while (!q_city.empty()) {
            int curr_city = q_city.front(); q_city.pop();
            
            for (int i = 0; i < graph[curr_city].size(); i++) {
                int next = graph[curr_city][i];
                
                if (isVisited[next]) continue;
                
                isVisited[next] = true;
                q_city.push(next);
                if (ans > city_cost[next]) ans = city_cost[next];
            }
        }
        return ans;
    }
};