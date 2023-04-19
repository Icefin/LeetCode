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
    int longestZigZag(TreeNode* root) {
        recursive(root->right, 1, 0);
        recursive(root->left, 0, 0);
        return res;
    }
    
private :
    int res = 0;
    void recursive(TreeNode* node, int direction, int cnt) {
        if (node == nullptr) {
            if (cnt > res)
                res = cnt;
            return ;
        }
        
        if (direction == 1) {
            recursive(node->right, 1, 0);
            recursive(node->left, 0, cnt + 1);
        }
        else {
            recursive(node->right, 1, cnt + 1);
            recursive(node->left, 0, 0);
        }
    }
};