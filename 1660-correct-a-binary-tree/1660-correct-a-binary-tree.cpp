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
    TreeNode* correctBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root, nullptr});

        while (!q.empty()) {
            int n = q.size();

            unordered_set<TreeNode*> visited;

            for (int i = 0; i < n; i++) {

                auto [node, parent] = q.front(); q.pop();
                if (visited.count(node->right)) {
                    if (parent->left == node)
                        parent->left = nullptr;
                    else
                        parent->right = nullptr;
                    return root;
                }
                visited.insert(node);

                if (node->right)
                    q.push({node->right, node});
                if (node->left)
                    q.push({node->left, node});
            }
        }

        return root;  
    }
};