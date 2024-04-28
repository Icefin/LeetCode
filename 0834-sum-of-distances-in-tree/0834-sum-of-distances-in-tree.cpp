class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for (auto elem : edges){
            graph[elem[0]].push_back(elem[1]);
            graph[elem[1]].push_back(elem[0]);
        }

        vector<int> childCnt(n, -1);
        childCnt[0] = n - 1;
        dfsGetChildCnt(graph, childCnt, 0, 0);

        vector<int> ans(n, -1);
        ans[0] = rootDistance;
        dfsGetDistance(graph, ans, childCnt, 0);
        return ans;
    }

private :
    int rootDistance = 0;
    int dfsGetChildCnt(const vector<vector<int>>& graph, vector<int>& childCnt, int num, int depth) {
        int sum = 0;
        for (int i = 0; i < graph[num].size(); i++) {
            if (childCnt[graph[num][i]] == -1) {
                childCnt[num] = 0;
                sum += dfsGetChildCnt(graph, childCnt, graph[num][i], depth + 1);
            }
        }

        rootDistance += depth;
        childCnt[num] = sum;
        return sum + 1;
    }

    void dfsGetDistance(const vector<vector<int>>& graph, vector<int>& ans, const vector<int>& childCnt, int num) {
        for (int i = 0; i < graph[num].size(); i++) {
            if (ans[graph[num][i]] == -1) {
                ans[graph[num][i]] = ans[num] + (graph.size() - 2 * (childCnt[graph[num][i]] + 1));
                dfsGetDistance(graph, ans, childCnt, graph[num][i]);
            }
        }
    }
};