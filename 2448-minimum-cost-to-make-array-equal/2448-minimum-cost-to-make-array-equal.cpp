class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long res;
        int n = nums.size();
        
        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            long long mcost = getCost(nums, cost, mid);
            long long mpcost = getCost(nums, cost, mid + 1);
            res = min(mcost, mpcost);
            if (mcost > mpcost)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return res;
    }
    
private :
    long long getCost(vector<int>& nums, vector<int>& cost, int target) {
        long long res = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            res += (long long)cost[i] * abs(nums[i] - target);
        return res;
    }
};