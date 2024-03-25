class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<uint8_t> iVisited(n + 1, 0);
        
        for (int i = 0; i < n; ++i) {
            iVisited[nums[i]]++;
        }
        
        vector<int> res;
        for (int i = 1; i <= n; ++i) {
            if (iVisited[i] < 2)
                continue;
            res.push_back(i);
        }
        return res;
    }
};