class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        std::map<int, int> bucket;
        for (int i = 0; i < arr.size(); ++i) {
            bucket[arr[i]]++;
        }
        
        std::map<int, int> freq;
        for (auto elem : bucket) {
            freq[elem.second]++;
        }
        
        int res = bucket.size();
        for (auto elem : freq) {
            if (k >= elem.first * elem.second) {
                k -= elem.first * elem.second;
                res -= elem.second;
            }
            else {
                res -= k / elem.first;
                break;
            }
        }
        return res;
    }
};