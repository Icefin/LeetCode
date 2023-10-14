class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        res = vector<vector<int>>();
        buff = vector<int>();
        for (int i = 0; i < candidates.size(); ++i)
            dfs(candidates, i, 0, target);
        return res;
    }
    
private :
    vector<vector<int>> res;
    vector<int>         buff;
    void dfs(vector<int>& candidates, int idx, int sum, int target) {
        if (idx == candidates.size())
            return;
        
        buff.push_back(candidates[idx]);
        sum += candidates[idx];
        if (sum >= target) {
            if (sum == target)
                res.push_back(buff);
            buff.pop_back();
            sum -= candidates[idx];
            return;
        }
        
        for (int i = idx; i < candidates.size(); ++i)
            dfs(candidates, i, sum, target);
        buff.pop_back();
        sum -= candidates[idx];
    }
};