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
    int equalToDescendants(TreeNode* root) {
        int res = 0;
        dfs(root, &res);
        return res;
    }
    
private:
    long long dfs(TreeNode* node, int* res) {
        if (node == nullptr)
            return 0;
        
        long long left = dfs(node->left, res);
        long long right = dfs(node->right, res);
        if (left + right == node->val)
            *res += 1;
        return left + right + node->val;
    }
};