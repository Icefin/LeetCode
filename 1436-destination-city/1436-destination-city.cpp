class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map<string, int> mp;
        
        for (vector<string>& path : paths) {
            mp[path[0]]++;
            mp[path[1]]++;
        }
        
        vector<string> candidates;
        for (auto p : mp) {
            if (p.second == 1)
                candidates.push_back(p.first);
        }
        
        for (vector<string>& path : paths)
            if (path[0] == candidates[0])
                return candidates[1];
        return candidates[0];
    }
};