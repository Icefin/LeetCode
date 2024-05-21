class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        makeSet(nums, vector<int>(), ans, 0);
        return ans;
    }

private :
    void makeSet(vector<int>& nums, vector<int> set, vector<vector<int>>& ans, int ptr) {
        if (ptr >= nums.size()) {
            ans.push_back(set);
            return;
        }

        makeSet(nums, set, ans, ptr + 1);
        set.push_back(nums[ptr]);
        makeSet(nums, set, ans, ptr + 1);
    }
};