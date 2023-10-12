class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int dup = 0;
        
        int n = nums.size();
        int prev = nums[0];
        int cnt = 1;
        for (int i = 1; i < n; ++i) {
            if (prev == nums[i]) {
                cnt++;
                if (cnt > 2) {
                    nums[i] = 1e9;
                    dup++;
                }
            }
            else {
                prev = nums[i];
                cnt = 1;
            }
        }
        
        sort(nums.begin(), nums.end());
        return (n - dup);
    }
};