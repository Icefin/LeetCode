class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int cnt[101];
        memset(cnt, 0, sizeof(cnt));
        
        int n = nums.size();
        for (int i = 0; i < n; ++i)
            cnt[nums[i]]++;
        
        int res = 0;
        for (int i = 1; i <= 100; ++i)
            res += cnt[i] * (cnt[i] - 1) / 2;
        
        return res;
    }
};