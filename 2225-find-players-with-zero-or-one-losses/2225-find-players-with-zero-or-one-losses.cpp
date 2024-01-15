class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> res(2, vector<int>(0));
        map<int, int> mp;
        
        for (int i = 0; i < matches.size(); ++i) {
            mp[matches[i][0]] += 0;
            mp[matches[i][1]] += 1;
        }
        
        for (const pair<int, int>& p : mp) {
            if (p.second == 0)
                res[0].push_back(p.first);
            else if (p.second == 1)
                res[1].push_back(p.first);
        }
        return res;
    }
};