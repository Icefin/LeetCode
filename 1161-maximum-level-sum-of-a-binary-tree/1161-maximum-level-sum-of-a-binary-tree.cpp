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
    int maxLevelSum(TreeNode* root) {
        int res = 0;
        int sum = INT_MIN;
        int level = 0;

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            level++;
            int curr = 0;
            for (int n = q.size(); n > 0; --n) {
                TreeNode* node = q.front(); q.pop();
                curr += node->val;

                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            if (sum < curr) {
                sum = curr;
                res = level;
            }
        }
        return res;
    }
};