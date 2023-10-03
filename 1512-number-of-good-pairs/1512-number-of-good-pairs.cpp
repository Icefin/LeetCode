class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int cnt[101];
        memset(cnt, 0, sizeof(cnt));
        
        int res = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            res += cnt[nums[i]];
            cnt[nums[i]]++;
        }
            
        return res;
    }
};