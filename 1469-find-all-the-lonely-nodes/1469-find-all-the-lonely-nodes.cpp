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
    vector<int> getLonelyNodes(TreeNode* root) {
        vector<int> res;
        dfs(root, &res);
        return res;
    }

private:
    bool dfs(TreeNode* node, vector<int>* ptr) {
        if (node == nullptr)
            return false;
        
        bool hasLeftChild = dfs(node->left, ptr);
        bool hasRightChild = dfs(node->right, ptr);
        if (hasLeftChild == true && hasRightChild == true) {
            return true;
        }
        if (hasLeftChild == true)
            ptr->push_back(node->left->val);
        if (hasRightChild == true)
            ptr->push_back(node->right->val);
        return true;
    }
};