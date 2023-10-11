class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> tmp(n + m);
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (nums1[i] > nums2[j]) {
                tmp[i + j] = nums2[j];
                j++;
            }
                
            else {
                tmp[i + j] = nums1[i];
                i++;
            }
                
        }
        
        while (i < m) {
            tmp[i + j] = nums1[i];
            i++;
        } 
        while (j < n) {
            tmp[i + j] = nums2[j];
            j++;
        } 
        
        for (int i = 0; i < n + m; ++i)
            nums1[i] = tmp[i];
    }
};