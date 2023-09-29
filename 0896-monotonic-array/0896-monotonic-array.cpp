class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        return (isIncreasing(nums) || isDecreasing(nums));
    }
    
private :
    bool isIncreasing(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] > nums[i + 1])
                return false;
        }
        return true;
    }
    
    bool isDecreasing(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] < nums[i + 1])
                return false;
        }
        return true;
    }
};