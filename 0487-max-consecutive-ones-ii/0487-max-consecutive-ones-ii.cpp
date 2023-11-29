class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0;
        int left = 0, right = 0;
        int zero_cnt = 0;
        
        int n = nums.size();
        while (right < n) {
            if (nums[right] == 0)
                zero_cnt++;
            
            while (zero_cnt == 2) {
                if (nums[left] == 0)
                    zero_cnt--;
                left++;
            }
            
            res = max(res, right - left + 1);
            right++;
        }
        return res;
    }
};