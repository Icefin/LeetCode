class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<tuple<int, int, int>> v(n);
        
        for (int i = 0; i < n; ++i)
            v[i] = {startTime[i], endTime[i], profit[i]};
        sort(v.begin(), v.end(), [&](auto& t1, auto& t2) {
            if (get<1>(t1) == get<1>(t2))
                return (get<2>(t1) > get<2>(t2));
            return (get<1>(t1) < get<1>(t2));
        });
        
        vector<int> dp(n, 0);
        dp[0] = get<2>(v[0]);
        for (int i = 1; i < n; ++i) {
            int left = 0, right = i - 1, idx = -1;
            
            while (left <= right) {
                int mid = left + (right - left) / 2;
                
                if (get<1>(v[mid]) <= get<0>(v[i])) {
                    idx = mid;
                    left = mid + 1;
                }
                else
                    right = mid - 1;
            }
            
            if (idx == -1)
                dp[i] = max(dp[i - 1], get<2>(v[i]));
            else
                dp[i] = max(dp[i - 1], dp[idx] + get<2>(v[i]));
        }
        return dp[n - 1];
    }
};