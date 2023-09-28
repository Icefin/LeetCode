class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int pos = 0;
        
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] % 2 == 0) {
                int temp = nums[pos];
                nums[pos] = nums[i];
                nums[i] = temp;
                pos++;
            }
        }
        return nums;
    }
};