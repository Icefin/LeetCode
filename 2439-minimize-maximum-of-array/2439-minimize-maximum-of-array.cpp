class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long ans = nums[0];
        long long sum = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            sum += nums[i];
            ans = max(ans,(sum+i)/(i+1));
        }
        return ans;
    }
};