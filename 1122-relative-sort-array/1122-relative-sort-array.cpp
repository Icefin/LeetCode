class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();
        
        unordered_map<int, int> mp;
        for (int i = 0; i < m; ++i)
            mp[arr2[i]] = 0;
        
        vector<int> buffer;
        for (int i = 0; i < n; ++i) {
            if (mp.find(arr1[i]) != mp.end()) {
                mp[arr1[i]]++;
            }
            else {
                buffer.push_back(arr1[i]);
            }
        }
        
        sort(buffer.begin(), buffer.end());
        
        vector<int> res;
        for (int i = 0; i < m; ++i) {
            int cnt = mp[arr2[i]];
            for (int j = 0; j < cnt; ++j)
                res.push_back(arr2[i]);
        }
        for (int i = 0; i < buffer.size(); ++i)
            res.push_back(buffer[i]);
        return res;
    }
};