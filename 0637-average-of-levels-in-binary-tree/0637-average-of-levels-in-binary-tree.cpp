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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        
        queue<TreeNode*> q;
        q.push(root);
        while (q.empty() == false) {
            int size = q.size();
            long long sum = 0;
            for (int cnt = 0; cnt < size; ++cnt) {
                TreeNode* current = q.front(); q.pop();
                sum += current->val;
                if (current->left != nullptr)
                    q.push(current->left);
                if (current->right != nullptr)
                    q.push(current->right);
            }
            res.push_back(static_cast<double>(sum) / size);
        }
        return res;
    }
};