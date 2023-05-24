class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int, int>> v;
        for(int i = 0; i < n; i++){
            v.push_back({nums2[i], nums1[i]});
        }
        sort(v.begin(), v.end(), greater<>());
        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum = 0;
        for(int i = 0; i < k; i++){
            sum += v[i].second;
            pq.push(v[i].second);
        }
        
        long long res = sum * v[k-1].first;
        for(int i = k; i < n; i++){
            sum = (sum + v[i].second - pq.top()); pq.pop();
            pq.push(v[i].second);
            res = max(res, sum * v[i].first);
        }
        return res;
    }
};
/*
14 13
2  11
1  7
12 6
*/