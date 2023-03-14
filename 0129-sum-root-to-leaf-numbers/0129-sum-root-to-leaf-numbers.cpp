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
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        dfs(root, ans, 0);
        return (ans);
    }
    
    void dfs(TreeNode* node, int& ans, int sum) {
        if (node->left == nullptr && node->right == nullptr) {
            sum = sum * 10 + node->val;
            ans += sum;
            return ;
        }
        
        sum = sum * 10 + node->val;
        if (node->left != nullptr)
            dfs(node->left, ans, sum);
        if (node->right != nullptr)
            dfs(node->right, ans, sum);
    }
};