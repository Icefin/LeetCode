class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> res;
        queue<pair<int, int>> q;
        q.push({0, 0});
        
        while (q.empty() == false) {
            int cr = q.front().first;
            int cc = q.front().second;
            q.pop();
            
            res.push_back(nums[cr][cc]);
            
            if (cc == 0 && cr + 1 < nums.size())
                q.push({cr + 1, cc});
            if (cc + 1 < nums[cr].size())
                q.push({cr, cc + 1});
        }
        return res;
    }
};