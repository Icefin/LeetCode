class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = -1;
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum >= k) {
                right--;
            }
            else {
                left++;
                if (sum > ans)
                    ans = sum;
            }
        }
        return ans;
    }
};