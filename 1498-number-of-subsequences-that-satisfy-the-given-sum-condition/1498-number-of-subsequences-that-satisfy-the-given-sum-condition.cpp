class Solution {
public:
    int MOD = 1e9 + 7;
    int numSubseq(vector<int>& nums, int target) {
        int res = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int>pow(n,1);
        for(int i = 1; i < n; i++){
            pow[i] = (pow[i-1] * 2) % MOD;
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] * 2 > target) {
                break;
            }
            int left = i, right = nums.size() - 1;
            int tidx = -1;
            while (left <= right) {
                int mid = (left + right) / 2;
                if (nums[i] + nums[mid] <= target) {
                    tidx = mid;
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
            res = (res + pow[tidx - i]) % MOD;
        }
        return res;
    }
};