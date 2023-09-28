class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<pair<int, int>> remain_pair;
        
        int n = nums.size();
        for (int i = 0; i < n; ++i)
            remain_pair.push_back({nums[i] % 2, nums[i]});
        
        sort(remain_pair.begin(), remain_pair.end());
        for (int i = 0; i < n; ++i)
            nums[i] = remain_pair[i].second;
        
        return nums;
    }
};