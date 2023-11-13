class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for (int i = 0; i < nums.size(); ++i) {
            while (i < nums.size() && nums[i] == val) {
                nums[i] = nums.back();
                nums.pop_back();
            }
        }
        return (nums.size());
    }
};