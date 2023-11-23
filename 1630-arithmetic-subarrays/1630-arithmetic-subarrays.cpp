class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int m = l.size();
        vector<bool> res(m, true);

        for (int i = 0; i < m; ++i) {
            int cl = l[i], cr = r[i];
            
            vector<int> v(nums.begin() + cl, nums.begin() + cr + 1);
            sort(v.begin(), v.end());
            int k = v.size();
            for (int j = 0; j < k - 1; ++j)  {
                if (v[j + 1] - v[j] != v[1] - v[0]) {
                    res[i] = false;
                    break;
                }
            }
        }
        return res;
    }
};