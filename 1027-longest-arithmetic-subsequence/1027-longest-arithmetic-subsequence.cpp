class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        if(n <= 2)
            return n;
        
        vector<unordered_map<int, int>> v(n);
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                int diff = nums[i] - nums[j];
                v[i][diff] = (v[j][diff] > 0) ? v[j][diff] + 1 : 1;
                res = max(res, v[i][diff] );
            }
        }
        return res + 1;
    }
};