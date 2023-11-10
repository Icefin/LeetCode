class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> um;
        int n = adjacentPairs.size();
        
        for (int i = 0; i < n; ++i) {
            um[adjacentPairs[i][0]].push_back(adjacentPairs[i][1]);
            um[adjacentPairs[i][1]].push_back(adjacentPairs[i][0]);
        }
        
        int start_num;
        for (auto elem : um) {
            if (elem.second.size() == 1) {
                start_num = elem.first;
                break ;
            }
        }
        
        n = um.size();
        vector<int> res(n);
        res[0] = start_num;
        res[1] = um[start_num][0];
        for (int i = 2; i < n; ++i)
            res[i] = (um[res[i - 1]][0] == res[i - 2]) ? um[res[i - 1]][1] : um[res[i - 1]][0];
        return (res);
    }
};