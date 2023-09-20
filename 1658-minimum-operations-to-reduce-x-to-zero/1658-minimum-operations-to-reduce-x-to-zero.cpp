class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        
        int window_size = -1;
        int left = 0;
        int current = 0;
        int n = nums.size();
        for (int right = 0; right < n; right++)
        {
            current += nums[right];
            
            while (current > total - x && left <= right)
            {
                current -= nums[left];
                left++;
            }
            
            if (current == total - x)
                window_size = max(window_size, right - left + 1);
        }
        
        if (window_size == -1)
            return -1;
        return n - window_size;
    }
};