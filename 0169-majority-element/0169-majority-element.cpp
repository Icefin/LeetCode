class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = nums.size() / 2;
        unordered_map<int, int> um;
        for (int i = 0; i < nums.size(); i++) {
            um[nums[i]]++;
            if (um[nums[i]] > majority) {
                return nums[i];
            }
        }
        return 0;
    }
};