class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<array<int, 26>, vector<int>> mp;
        
        for (int i = 0; i < strs.size(); ++i) {
            array<int, 26> arr;
            arr.fill(0);
            
            for (int j = 0; j < strs[i].length(); ++j) {
                arr[strs[i][j] - 'a']++;
            }
            
            mp[arr].push_back(i);
        }
        
        map<array<int, 26>, vector<int>>::iterator iter = mp.begin();
        vector<vector<string>> res(mp.size());
        for (int i = 0; i < res.size(); ++i) {
            for (int j = 0; j < iter->second.size(); ++j) {
                res[i].emplace_back(strs[iter->second[j]]);
            }
            iter++;
        }
        return res;
    }
};