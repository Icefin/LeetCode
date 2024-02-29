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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool isEvenLevel = true;
        while (q.empty() == false) {
            int qSize = q.size();
            int prev = isEvenLevel == true ? 0 : 1e9;
            for (int i = 0; i < qSize; ++i) {
                TreeNode* node = q.front(); q.pop();
                
                if (isEvenLevel == true) {
                    if (node->val % 2 == 0 || prev >= node->val)
                        return false;
                }
                else if (isEvenLevel == false) {
                    if (node->val % 2 != 0 || prev <= node->val)
                        return false;
                }
                
                prev = node->val;
                if (node->left != nullptr)
                    q.push(node->left);
                if (node->right != nullptr)
                    q.push(node->right);
            }
            isEvenLevel = !isEvenLevel;
        }
        return true;
    }
};