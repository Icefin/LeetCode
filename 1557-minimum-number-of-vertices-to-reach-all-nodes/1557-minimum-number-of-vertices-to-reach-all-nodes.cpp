class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> res;
        vector<bool> v(n, false);
        for (auto edge : edges) {
            v[edge[1]] = true;
        }
        for (int i = 0; i < n; i++) {
            if (v[i] == false) {
                res.push_back(i);
            }
        }
        return res;
    }
};

//topological sort
//100000