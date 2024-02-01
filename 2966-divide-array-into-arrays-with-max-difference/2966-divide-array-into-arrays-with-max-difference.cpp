class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> res;
        
        std::sort(nums.begin(), nums.end());
        for (int i = 2; i < n; i += 3) {
            if (nums[i] - nums[i - 2] > k)
                return res;
        }
        
        int rsize = n / 3;
        res.resize(rsize);
        for (int i = 0; i < rsize; ++i) {
            res[i] = {nums[3 * i], nums[3 * i + 1], nums[3 * i + 2]};
        }
        return res;
    }
};