class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        vector<int> res(n, 0);
        res[0] = pref[0];
        int bit = res[0];
         
        for (int i = 1; i < n; ++i) {
            res[i] = bit ^ pref[i];
            bit = bit ^ res[i];
        }
        return res;
    }
};