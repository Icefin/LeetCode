class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> um;
        
        int n = nums.size();
        for (int i = 0; i < n; ++i)
            um[nums[i]]++;
        
        vector<int> res;
        
        int det = nums.size() / 3;
        for (auto p : um) {
            if (p.second  > det)
                res.push_back(p.first);
        }
        return res;
    }
};