class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        unordered_map<int, int> um_num;
        um_num[0] = 0;

        int res = 0;
        for (int i = 1; i <= n; i++) {
            prefix[i] = (nums[i - 1] == 0) ? prefix[i - 1] - 1 : prefix[i - 1] + 1;

            if (um_num.find(prefix[i]) != um_num.end()) {
                res = max(res, i - um_num[prefix[i]]);
            }
            else {
                um_num[prefix[i]] = i;
            }
        }
        
        return res;
    }
};