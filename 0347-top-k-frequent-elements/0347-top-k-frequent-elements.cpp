class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        for (int i = 0; i < nums.size(); i++) {
            um[nums[i]]++;
        }
        
        priority_queue<pair<int, int>> pq;
        for (auto num : um) {
            pq.push({num.second, num.first});
        }
        
        vector<int> res;
        for (int i = 0; i < k; i++) {
            pair<int, int> elem = pq.top(); pq.pop();
            res.push_back(elem.second);
        }
        return res;
    }
};