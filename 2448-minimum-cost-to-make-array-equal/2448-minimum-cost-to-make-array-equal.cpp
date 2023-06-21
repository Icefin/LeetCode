class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
            v.push_back({nums[i], cost[i]});
        sort(v.begin(), v.end());
        
        long long res = 0;
        int left = v[0].first;
        int right = v[n - 1].first;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            long long mcost = getCost(v, mid);
            long long mpcost = getCost(v, mid + 1);
            res = min(mcost, mpcost);
            if (mcost > mpcost)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return res;
    }
    
private :
    long long getCost(vector<pair<int, int>>& v, int target) {
        long long res = 0;
        int n = v.size();
        for (int i = 0; i < n; i++)
            res += (long long)v[i].second * abs(v[i].first - target);
        return res;
    }
};