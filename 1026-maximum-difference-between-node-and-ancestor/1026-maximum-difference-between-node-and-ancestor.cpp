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
    int maxAncestorDiff(TreeNode* root) {
        dfs(root->left, root->val, root->val);
        dfs(root->right, root->val, root->val);
        return res;
    }
    
private :
    int res = 0;
    void dfs(TreeNode* node, int max, int min) {
        if (node == nullptr)
            return;
        
        res = std::max(res, abs(max - node->val));
        res = std::max(res, abs(min - node->val));
        
        max = std::max(max, node->val);
        min = std::min(min, node->val);
        
        dfs(node->left, max, min);
        dfs(node->right, max, min);
    }
};