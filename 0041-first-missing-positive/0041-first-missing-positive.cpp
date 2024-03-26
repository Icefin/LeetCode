class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<bool> bIsChecked(n + 1, false);

        for (int num : nums) {
            if (num > 0 && num <= n) {
                bIsChecked[num] = true;
            }
        }

        for (int i = 1; i <= n; ++i) {
            if (bIsChecked[i] == false) {
                return i;
            }
        }

        return n + 1;
    }
};