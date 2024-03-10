class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        bool bucket1[1001];
        memset(bucket1, false, sizeof(bucket1));
        for (int i = 0; i < nums1.size(); ++i)
            bucket1[nums1[i]] = true;
        
        bool bucket2[1001];
        memset(bucket2, false, sizeof(bucket2));
        for (int i = 0; i < nums2.size(); ++i)
            bucket2[nums2[i]] = true;
        
        vector<int> res;
        for (int i = 0; i < 1001; ++i) {
            if (bucket1[i] == true && bucket2[i] == true)
                res.push_back(i);
        }
        return res;
    }
};