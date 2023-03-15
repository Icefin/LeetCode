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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q_node;
        q_node.push(root);
        bool isSpaceExist = false;
        while (!q_node.empty()) {
            int total_cnt = q_node.size();
            while (total_cnt--) {
                TreeNode* curr = q_node.front(); q_node.pop();
                if (curr == nullptr) {
                    isSpaceExist = true;
                    continue ;
                }
                if (isSpaceExist == true) {
                    return (false);
                }
                q_node.push(curr->left);
                q_node.push(curr->right);
            }
        }
        return (true);
    }
};