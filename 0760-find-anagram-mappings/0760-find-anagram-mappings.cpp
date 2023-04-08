class Solution {
public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> um_num2_idx;
        for (int i = 0; i < nums2.size(); i++)
            um_num2_idx[nums2[i]] = i;
        vector<int> ans(nums1.size());
        for (int i = 0; i <nums1.size(); i++) {
            ans[i] = um_num2_idx[nums1[i]];
        }
        return ans;
    }
};