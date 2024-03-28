class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int res = 0;
        unordered_map<int, int> frequency;
        int n = nums.size();
        for (int l = 0, r = 0; r < n; ++r) {
            frequency[nums[r]]++;
            while (frequency[nums[r]] > k) {
                frequency[nums[l]]--;
                l++;
            }
            
            res = max(res, r - l + 1);
        }
        return res;
    }
};