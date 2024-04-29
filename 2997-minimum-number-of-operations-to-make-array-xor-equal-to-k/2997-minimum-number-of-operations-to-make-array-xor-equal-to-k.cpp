class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int flip = 0;
        for (int n : nums) {
            flip = flip ^ n;
        }
        
        return __builtin_popcount(flip ^ k);
    }
};