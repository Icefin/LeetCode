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
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        if (root == nullptr)
            return result;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (q.empty() == false) {
            int n = q.size();
            
            int max_value = INT_MIN;
            for (int i = 0; i < n; ++i) {
                TreeNode* node = q.front(); q.pop();
                
                if (node->val > max_value)
                    max_value = node->val;
                
                if (node->left != nullptr)
                    q.push(node->left);
                if (node->right != nullptr)
                    q.push(node->right);
            }
            result.push_back(max_value);
        }
        return result;
    }
};