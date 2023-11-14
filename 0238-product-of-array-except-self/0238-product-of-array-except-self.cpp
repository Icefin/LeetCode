class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> bucket(61, 0);
        for (int num : nums)
            bucket[num + 30]++;
        
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            bucket[nums[i] + 30]--;
            if (bucket[30] > 0) {
                bucket[nums[i] + 30]++;
                nums[i] = 0;
                continue;
            }
            int product = 1;
            for (int j = 0; j < 61; ++j)
                if (bucket[j] != 0)
                    product *= pow((j - 30), bucket[j]);
            bucket[nums[i] + 30]++;
            nums[i] = product;
        }
        return nums;
    }
};