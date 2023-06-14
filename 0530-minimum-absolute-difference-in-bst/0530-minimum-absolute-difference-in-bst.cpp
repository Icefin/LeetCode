/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        int res = INT_MAX;
        vector<int> arr;
        inorder_traverse(root, arr);
        int n = arr.size();
        for (int i = 0; i < n - 1; i++) {
            res = min(res, abs(arr[i + 1] - arr[i]));
        }
        return res;
    }
    
private :
    void inorder_traverse(TreeNode* node, vector<int>& arr) {
        if (node == nullptr) {
            return;
        }
        
        inorder_traverse(node->left, arr);
        arr.push_back(node->val);
        inorder_traverse(node->right, arr);
    }
};