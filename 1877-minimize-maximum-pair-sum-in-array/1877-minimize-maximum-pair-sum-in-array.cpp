class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1;
        
        int max_sum = 0;
        while (left < right) {
            if (nums[left] + nums[right] > max_sum)
                max_sum = nums[left] + nums[right];
            left++;
            right--;
        }
        return max_sum;
    }
};