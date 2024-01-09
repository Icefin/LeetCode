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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1, v2;
        inorder(root1, v1);
        inorder(root2, v2);
        
        if (v1.size() != v2.size())
            return false;
        for (int i = 0; i < v1.size(); ++i) {
            if (v1[i] != v2[i])
                return false;
        }
        return true;
    }
    
    void inorder(TreeNode* node, vector<int>& v) {
        if (node == nullptr)
            return;
        
        inorder(node->left, v);
        if (node->left == nullptr && node->right == nullptr)
            v.push_back(node->val);
        inorder(node->right, v);
    }
};