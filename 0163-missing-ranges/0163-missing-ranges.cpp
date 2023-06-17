class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<vector<int>> res;
        
        int n = nums.size();
        int left = lower;
        for (int i = 0; i < n; i++) {
            int range = nums[i] - left;
            if (range >= 1) 
                res.push_back({left, nums[i] - 1});
            left = nums[i] + 1;
        }
        if (left <= upper)
            res.push_back({left, upper});
        return res;
    }
};