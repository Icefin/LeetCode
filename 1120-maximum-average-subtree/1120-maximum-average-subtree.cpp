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
    double maximumAverageSubtree(TreeNode* root) {
        double res = 0;
        postOrderTraverse(root, &res);    
        return res;
    }
    
private :
    pair<int, int> postOrderTraverse(TreeNode* root, double *res) {
        pair<int, int> lSub = {0, 0};
        pair<int, int> rSub = {0, 0};
        if (root->left != nullptr)
            lSub = postOrderTraverse(root->left, res);
        if (root->right != nullptr)
            rSub = postOrderTraverse(root->right, res);
        
        int totVal = (lSub.first + rSub.first + root->val);
        int totCnt = (lSub.second + rSub.second + 1);
        double subavg = static_cast<double>(totVal) / static_cast<double>(totCnt);
        if (subavg > *res)
            *res = subavg;
        return {totVal, totCnt};
    } 
};