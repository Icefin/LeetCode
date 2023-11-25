class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        
        vector<int> prefix(n, 0);
        prefix[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            prefix[i] = prefix[i - 1] + nums[i];
        }
            
        for (int i = 0; i < n; ++i) {
            res[i] = nums[i] * (i + 1) - prefix[i] + prefix[n - 1] - prefix[i] - nums[i] * (n - i - 1);
        }
        
        return res;
    }
};