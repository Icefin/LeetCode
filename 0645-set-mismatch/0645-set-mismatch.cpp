class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<char> v(n + 1, 0);
        
        for (int i = 0; i < n; ++i)
            v[nums[i]]++;
        
        vector<int> res(2);
        for (int i = 1; i <= n; ++i) {
            if (v[i] == 2)
                res[0] = i;
            if (v[i] == 0)
                res[1] = i;
        }
        return res;
    }
};