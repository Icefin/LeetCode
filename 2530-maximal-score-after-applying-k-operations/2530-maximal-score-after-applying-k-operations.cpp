class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        std::priority_queue<int> pq;
        int cnt = nums.size();
        for (int i = 0; i < cnt; ++i)
            pq.push(nums[i]);
        
        long long res = 0;
        while (k > 0) {
            int num = pq.top(); pq.pop();
            res += num;
            pq.push(ceil(num / 3.0));
            k--;
        }
        return res;
    }
};