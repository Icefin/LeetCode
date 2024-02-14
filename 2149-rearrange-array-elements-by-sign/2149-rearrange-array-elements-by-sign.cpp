class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> res(n);
        
        int pt = 0;
        int nt = 1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] >= 0) {
                res[pt] = nums[i];
                pt += 2;
            }
            else {
                res[nt] = nums[i];
                nt += 2;
            }
        }
        return res;
    }
};