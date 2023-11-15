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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr)
            return false;
        return dfs(root, 0, targetSum);
    }
    
private :
    bool dfs(TreeNode* node, int sum, int target) {
        if (node->left == nullptr && node->right ==nullptr) {
            if (sum + node->val == target)
                return true;
            return false;
        }
        
        if (node->left != nullptr && dfs(node->left, sum + node->val, target) == true)
            return true;
        if (node->right != nullptr && dfs(node->right, sum + node->val, target) == true)
            return true;
        return false;
    }
};