class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        
        res.push_back(vector<int>(1, nums[0]));
        int idx = 0;
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            if (nums[i] == nums[i - 1]) {
                idx++;
                if (idx >= res.size())
                    res.push_back(vector<int>(1, nums[i]));
                else
                    res[idx].push_back(nums[i]);
            }
            else {
                res[0].push_back(nums[i]);
                idx = 0;
            }
        }
        return res;
    }
};