class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        unordered_map<int, int> um;
        um[0] = 0;
        for(int rod: rods){
            unordered_map<int, int> dp(um);
            for(auto& [diff,taller] : um){
                int shorter = taller - diff;
                dp[diff + rod] = max(dp[diff + rod], taller + rod);
                dp[abs(diff - rod)] = max(dp[abs(diff - rod)], max(shorter + rod, taller));
            }
            um = dp;
        }
        return um[0];
    }
};