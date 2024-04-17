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
    string smallestFromLeaf(TreeNode* root) {
        dfs(root, "");
        return res;
    }
    
private:
    string res;
    
    void dfs(TreeNode* node, string currentString) {
        if (node == nullptr) {
            return;
        }

        currentString = static_cast<char>(node->val + 'a') + currentString;
        
        if (node->left == nullptr && node->right == nullptr) { 
            if (res == "" || res > currentString) { 
                res = currentString;
            }
        }

        if (node->left != nullptr) {
            dfs(node->left, currentString);
        }

        if (node->right != nullptr) {
            dfs(node->right, currentString);
        }
    }
};