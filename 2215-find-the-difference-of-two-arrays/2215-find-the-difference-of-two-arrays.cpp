class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> res(2);
        unordered_set<int> us1(nums1.begin(), nums1.end());
        unordered_set<int> us2(nums2.begin(), nums2.end());
        for (auto num : us1) {
            if (us2.find(num) == us2.end()) {
                res[0].push_back(num);
            }
        }
        for (auto num : us2) {
            if (us1.find(num) == us1.end()) {
                res[1].push_back(num);
            }
        }
        return res;
    }
};