class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> res;
        for (int i = 0; i < equations.size(); i++) {
            string from = equations[i][0];
            string to = equations[i][1];
            um_graph[from].push_back({to, values[i]});
            um_graph[to].push_back({from, 1 / values[i]});
        }
        
        for (int i = 0; i < queries.size(); i++) {
            string from = queries[i][0];
            string to = queries[i][1];
            double val = getDivision(from, to);
            res.push_back(val);
        }
        return res;
    }
    
private :
    unordered_map<string, vector<pair<string, double>>> um_graph;
    
    double getDivision(string start, string dest) {
        if (start == dest) {
            if (um_graph[start].size() != 0)
                return 1.0;
            else
                return -1.0;
        }
        queue<pair<string, double>> q;
        unordered_set<string> isVisited;
        q.push({start, 1});
        isVisited.insert(start);
        while (!q.empty()) {
            pair<string, double> curr = q.front(); q.pop();
            string currNode = curr.first;
            double currVal = curr.second;
            for (int i = 0; i < um_graph[currNode].size(); i++) {
                string nextNode = um_graph[currNode][i].first;
                double nextVal = um_graph[currNode][i].second;
                if (isVisited.find(nextNode) != isVisited.end())
                    continue;
                isVisited.insert(nextNode);
                if (nextNode == dest) {
                    return currVal * nextVal;
                }
                else {
                    q.push({nextNode, currVal * nextVal});
                }
            }
        }
        return (-1.0);
    }
};