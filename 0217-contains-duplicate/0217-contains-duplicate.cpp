class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool> um;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (um[nums[i]])
                return true;
            um[nums[i]] = true;
        }
        return false;
    }
};