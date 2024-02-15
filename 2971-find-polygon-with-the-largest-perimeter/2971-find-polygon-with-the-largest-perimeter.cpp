class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<long long> prefixSum(n);
        prefixSum[0] = nums[0];
        for (int i = 1; i < n; ++i)
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        
        for (int i = n - 1; i > 1; --i) {
            if (nums[i] < prefixSum[i - 1])
                return nums[i] + prefixSum[i - 1];
        }
        return -1;
    }
};