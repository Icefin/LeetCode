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
    int averageOfSubtree(TreeNode* root) {
        res = 0;
        post_order_traverse(root);
        return res;
    }
    
private :
    int res;
    pair<int, int> post_order_traverse(TreeNode* node) {
        if (node == nullptr)
            return {0, 0};
        
        pair<int, int> lp = post_order_traverse(node->left);
        pair<int, int> rp = post_order_traverse(node->right);
        
        int sum = lp.first + rp.first + node->val;
        int cnt = lp.second + rp.second + 1;
        int average = sum / cnt;
        
        if (average == node->val)
            res++;
        return {sum, cnt};
    }
};