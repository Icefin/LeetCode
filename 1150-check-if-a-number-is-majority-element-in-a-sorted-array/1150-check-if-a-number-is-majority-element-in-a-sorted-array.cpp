class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int uidx = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
        int lidx = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        return ((uidx - lidx + 1) > nums.size() / 2);
    }
};