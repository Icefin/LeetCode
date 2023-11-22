class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        priority_queue<pair<int, int>> pq_min;
        priority_queue<pair<int, int>> pq_max;
        int m = arrays.size();
        for (int i = 0; i < m; ++i) {
            pq_min.push({arrays[i][0], i});
            pq_max.push({-arrays[i].back(), i});
            
            if (pq_min.size() > 2)
                pq_min.pop();
            if (pq_max.size() > 2)
                pq_max.pop();
        }
        
        int res = 0;
        pair<int, int> min_1 = pq_min.top(); pq_min.pop();
        pair<int, int> min_2 = pq_min.top(); pq_min.pop();
        pair<int, int> max_1 = pq_max.top(); pq_max.pop();
        pair<int, int> max_2 = pq_max.top(); pq_max.pop();
        if (min_1.second != max_1.second)
            res = max(res, abs(-max_1.first - min_1.first));
        if (min_1.second != max_2.second)
            res = max(res, abs(-max_2.first - min_1.first));
        if (min_2.second != max_1.second)
            res = max(res, abs(-max_1.first - min_2.first));
        if (min_2.second != max_2.second)
            res = max(res, abs(-max_2.first - min_2.first));
        return res;
    }
};

//#1. O(nlogn + n)
//#2. O(n)
//#3. O(2n)