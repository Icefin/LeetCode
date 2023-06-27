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
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        return traverse(root1, root2, target);
    }
    
private :
    bool traverse(TreeNode* r1, TreeNode* r2, int t) {
        if (r1 == nullptr || r2 == nullptr)
            return false;
        
        int curr = r1->val + r2->val;
        if (curr == t)
            return true;
        
        if (curr > t)
            return (traverse(r1->left, r2, t) || traverse(r1, r2->left, t));
        else
            return (traverse(r1->right, r2, t) || traverse(r1, r2->right, t));
    }
};