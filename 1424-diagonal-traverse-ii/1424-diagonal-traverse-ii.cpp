bool compare(vector<int>& v1, vector<int>& v2) {
    if (v1[0] != v2[0])
        return v1[0] < v2[0];
    return v1[1] > v2[1];
}

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<vector<int>> pq;
        int n = nums.size();
        for (int r = 0; r < n; ++r) {
            int m = nums[r].size();
            for (int c = 0; c < m; ++c) {
                pq.push_back({r + c, r, nums[r][c]});
            }
        }
        
        sort(pq.begin(), pq.end(), compare);
        n = pq.size();
        vector<int> res(n);
        for (int i = 0 ; i < n; ++i) {
            res[i] = pq[i][2];
        }
        return res;
    }
};