class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long res = 0;
        
        long long zero_cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                zero_cnt++;
                continue ;
            }
            
            res += zero_cnt * (zero_cnt + 1) / 2;
            zero_cnt = 0;
        }
        res += zero_cnt * (zero_cnt + 1) / 2;
        return res;
    }
};