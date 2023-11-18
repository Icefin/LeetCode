class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        long long accum = 0;
        long long left = 0;
        
        int n = nums.size();
        for (int right = 0; right < n; ++right) {
            accum += nums[right];
            
            if ((right - left + 1) * nums[right] - accum > k) {
                accum -= nums[left];
                left++;
            }
        }
        
        return n - left;
    }
};