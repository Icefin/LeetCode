class Graph {
public:
    Graph(int n, vector<vector<int>>& edges) {
        graph = vector<vector<int>>(n,  vector<int>(n, 0));
        
        for (vector<int> edge : edges)
            graph[edge[0]][edge[1]] = edge[2];
    }
    
    void addEdge(vector<int> edge) {
        graph[edge[0]][edge[1]] = edge[2];
    }
    
    int shortestPath(int node1, int node2) {
        int n = graph.size();
        vector<int> dist(n, 1e9);
        dist[node1] = 0;
        priority_queue<pair<int, int>> pq;
        pq.push(make_pair(node1, 0));
        
        while (pq.empty() == false) {
            int current_node = pq.top().first;
            int distance = -pq.top().second;
            pq.pop();
            
            if (dist[current_node] < distance)
                continue;
            
            for (int i = 0; i < n; ++i) {
                if (graph[current_node][i] == 0)
                    continue;
                
                int next = i;
                int cost = graph[current_node][i] + distance;
                
                if (cost < dist[next]) {
                    dist[next] = cost;
                    pq.push(make_pair(next, -cost));
                }
            }
        }
        if (dist[node2] == 1e9)
            return -1;
        return dist[node2];
    }
    
private :
    vector<vector<int>> graph;
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */