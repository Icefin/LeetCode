class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> res;
        int n = nums.size();
        if (2 * k + 1 > n) {
            res = vector<int>(n, -1);
            return res;
        }
        
        long long sum = 0;
        for (int i = -k; i < n; i++) {
            if (i < 0) {
                sum += nums[i + k];
                continue;
            }
            else if (i + k >= n) {
                res.push_back(-1);
                continue;
            }
            else if (i - k < 0) {
                res.push_back(-1);
                sum += nums[i + k];
                continue;
            }
            sum += nums[i + k];
            res.push_back(sum / (2 * k + 1));
            sum -= nums[i - k];
        }
        return res;
    }
};