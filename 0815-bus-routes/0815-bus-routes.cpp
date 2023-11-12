//route[i][j] : from ith bus to jth route
//buses[i][j] : from ith route to jth bus

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int, bool> um_route_visited;
        unordered_map<int, vector<int>> buses;
        for (int i = 0; i < routes.size(); i++) {
            for (int j = 0; j < routes[i].size(); j++) {
                buses[routes[i][j]].push_back(i);
            }
        }

        queue<pair<int, int>> q;
        q.push({ 0, source });
        um_route_visited[source] = true;

        while (!q.empty()) {
            int dist = q.front().first;
            int curr_route = q.front().second;
            q.pop();

            if (curr_route == target){
                return dist;
            }

            for (int bus : buses[curr_route]) {
                for (int j = 0; j < routes[bus].size(); j++) {
                    if (!um_route_visited[routes[bus][j]]) {
                        um_route_visited[routes[bus][j]] = true;
                        q.push({ dist + 1, routes[bus][j] });
                    }
                }
                routes[bus].clear();
            }
        }
        return -1;
    }
};