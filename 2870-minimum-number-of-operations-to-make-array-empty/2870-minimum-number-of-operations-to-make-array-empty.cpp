class Solution {
public:
    int minOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int lower = i;
            int upper = upper_bound(nums.begin(), nums.end(), nums[lower]) - nums.begin() - 1;
            
            if (upper == lower)
                return -1;
            
            res += calculate_operation(upper - lower + 1);
            
            i = upper;
        }
        return res;
    }
    
private :
    int calculate_operation(int cnt) {
        if (cnt % 3 == 0)
            return cnt / 3;
        else if (cnt % 3 == 1)
            return 2 + (cnt - 4) / 3;
        else
            return 1 + (cnt - 2) / 3;
        return -1;
    }
};