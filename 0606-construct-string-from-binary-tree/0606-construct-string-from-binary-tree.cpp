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
    string tree2str(TreeNode* root) {
        string res = to_string(root->val);
        if (root->left != nullptr) {
            res += "(";
            res += tree2str(root->left);
            res += ")";
        }
        else if (root->right != nullptr) {
            res += "()";
        }
        if (root->right != nullptr) {
            res += "(";
            res += tree2str(root->right);
            res += ")";
        }
        return res;
    }
};