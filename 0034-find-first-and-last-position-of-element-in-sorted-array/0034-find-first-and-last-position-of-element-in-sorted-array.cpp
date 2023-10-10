class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lower_idx = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int upper_idx = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
        
        vector<int> res(2);
        if (lower_idx > upper_idx) {
            res[0] = res[1] = -1;
            return res;
        }
        res[0] = lower_idx;
        res[1] = upper_idx;
        return res;
    }
};