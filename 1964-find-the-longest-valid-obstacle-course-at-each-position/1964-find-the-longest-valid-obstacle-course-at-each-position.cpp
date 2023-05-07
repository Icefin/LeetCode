class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<int> ans(n, 1);
        vector<int> dp;

        for(int i=0;i<n;i++){
            int idx = upper_bound(dp.begin(), dp.end(), obstacles[i]) - dp.begin();
            if(idx < dp.size())
                dp[idx] = obstacles[i];
            else
                dp.push_back(obstacles[i]);
            ans[i] = idx+1;
        }
        return ans;
    }
};
