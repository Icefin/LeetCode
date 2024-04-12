class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> preorder(n, 0); preorder[0] = height[0];
        vector<int> postorder(n, 0); postorder[0] = height[n - 1];
        
        for (int i = 1; i < n; ++i) {
            preorder[i] = max(preorder[i - 1], height[i]);
            postorder[i] = max(postorder[i - 1], height[n - i - 1]);
        }
        
        int res = 0;
        for (int i = 1; i < n - 1; ++i) {
            int trapable = min(preorder[i - 1], postorder[n - i - 1]);
            if (trapable > height[i])
                res += trapable - height[i];
        }
        return res;
    }
};